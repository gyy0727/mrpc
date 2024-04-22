
#include "../user.pb.h"
#include "mrpcprovider.h"
#include"../rpcheader.pb.h"
#include <google/protobuf/descriptor.h>
#include <iostream>
class UserService : public fixbug::UserServiceRpc {
public:
  bool Login(std::string name, std::string pwd) {
    std::cout << "doing Login services " << std::endl;
    std::cout << "name = " << name << " pwd = " << pwd << std::endl;
    return true;
  }
  void Login(::google::protobuf::RpcController *controller,
             const ::fixbug::LoginRequest *request,
             ::fixbug::LoginResponse *response,
             ::google::protobuf::Closure *done) {
    std::string name = request->name();
    std::string pwd = request->pwd();
    //  bool result = Login(name, pwd);
    fixbug::ResultCode *rt = response->mutable_result();
    rt->set_errorcode(1);
    rt->set_errormsg("登录失败");
    response->set_success(true);
  }
  ~UserService() {
    
  }
  
};

int main() {
  RpcProvider provider;
  provider.NotifyService(new UserService());

  // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
  provider.Run();

  return 0;
}