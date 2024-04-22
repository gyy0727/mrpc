#include "mrpcprovider.h"
#include "../rpcheader.pb.h"
#include <google/protobuf/descriptor.h>
#include <muduo/net/InetAddress.h>

void RpcProvider::NotifyService(google::protobuf::Service *service) {
  ServiceInfo serviceinfo;
  const google::protobuf::ServiceDescriptor *servicedesc =
      service->GetDescriptor();
  std::string serviceName = servicedesc->name();
  int methodCount = servicedesc->method_count();

  for (int i = 0; i < methodCount; i++) {
    const google::protobuf::MethodDescriptor *methoddesc =
        servicedesc->method(i);
    std::string methodName = methoddesc->name();
    serviceinfo.m_methodMap.insert({methodName, methoddesc});
  }
  serviceinfo.m_service = service;
  m_serviceMap.insert({serviceName, serviceinfo});
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run() {
  std::string ip = "127.0.0..1";
  uint16_t port = 8001;
  muduo::net::InetAddress address(ip, port);
  muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");

  // 绑定连接回调和消息读写回调方法  分离了网络代码和业务代码
  server.setConnectionCallback(
      std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
  server.setMessageCallback(
      std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3));

  // 设置muduo库的线程数量
  server.setThreadNum(4);
  std::cout << "RpcProvider start service at ip:" << ip << " port:" << port
            << std::endl;

  // 启动网络服务
  server.start();
  m_eventLoop.loop();
}

// 新的socket连接回调
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn) {
  if (!conn->connected()) {
    // 和rpc client的连接断开了
    conn->shutdown();
  }
}

// 已建立连接用户的读写事件回调
// 如果远程有一个rpc服务的调用请求，那么OnMessage方法就会响应
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn,
                            muduo::net::Buffer *buffer, muduo::Timestamp) {
  std::string buf = buffer->retrieveAllAsString();
  uint32_t head_size = 0;
  buf.copy((char *)&head_size, 4, 0);
  std::string rpcHeaderStr = buf.substr(4, head_size);
  rpcheader::RpcHeader rpcHeader;
  std::string service_name;
  std::string method_name;
  uint32_t args_size;
  if (rpcHeader.ParseFromString(rpcHeaderStr)) {
    // 数据头反序列化成功
    service_name = rpcHeader.service_name();
    method_name = rpcHeader.method_name();
    args_size = rpcHeader.args_size();
  } else {
    // 数据头反序列化失败
    std::cout << "rpc_header_str:" << rpcHeaderStr << " parse error!"
              << std::endl;
    return;
  }
  std::string args_str = buf.substr(4 + head_size, args_size);

  // 打印调试信息
  std::cout << "============================================" << std::endl;
  std::cout << "header_size: " << head_size << std::endl;
  std::cout << "rpc_header_str: " << rpcHeaderStr << std::endl;
  std::cout << "service_name: " << service_name << std::endl;
  std::cout << "method_name: " << method_name << std::endl;
  std::cout << "args_str: " << args_str << std::endl;
  std::cout << "============================================" << std::endl;
  auto it = m_serviceMap.find(service_name);
  if (it == m_serviceMap.end()) {
    std::cout << service_name << " is not exist!" << std::endl;
    return;
  }
  auto mit = it->second.m_methodMap.find(method_name);
  if (mit == it->second.m_methodMap.end()) {
    std::cout << service_name << ":" << method_name << " is not exist!"
              << std::endl;
    return;
  }
  google::protobuf::Service *service =
      it->second.m_service; // 获取service对象  new UserService
  const google::protobuf::MethodDescriptor *method = mit->second;
  google::protobuf::Message *request =
      service->GetRequestPrototype(method).New();
  if (!request->ParseFromString(args_str)) {
    std::cout << "request parse error, content:" << args_str << std::endl;
    return;
  }
  google::protobuf::Message *response =
      service->GetResponsePrototype(method).New();

  // 给下面的method方法的调用，绑定一个Closure的回调函数
  google::protobuf::Closure *done =
      google::protobuf::NewCallback<RpcProvider,
                                    const muduo::net::TcpConnectionPtr &,
                                    google::protobuf::Message *>(
          this, &RpcProvider::SendRpcResponse, conn, response);
  service->CallMethod(method, nullptr, request, response, done);
}

// Closure的回调操作，用于序列化rpc的响应和网络发送
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn,
                                  google::protobuf::Message *response) {
  std::string response_str;
  if (response->SerializeToString(&response_str)) // response进行序列化
  {
    // 序列化成功后，通过网络把rpc方法执行的结果发送会rpc的调用方
    conn->send(response_str);
  } else {
    std::cout << "serialize response_str error!" << std::endl;
  }
  conn->shutdown(); // 模拟http的短链接服务，由rpcprovider主动断开连接
}