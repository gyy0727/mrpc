/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-19 12:27:38
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-11-22 19:19:08
 * @FilePath: /桌面/smallchat/src/server.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*************************************************************************
        > File Name: server.cc
        > Author: amoscykl
        > Mail: amoscykl@163.com
        > Created Time: 2023年11月19日 星期日 12时25分05秒
 ************************************************************************/
#include "../include/socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
  std::cout << "服务器端正在运行" << endl;
  // 1. 创建监听的套接字
  Socket socket_;
  int lfd = socket_.createSocket();
  
  if (lfd == -1) {
    perror("socket创建失败");
    exit(0);
  }

  // 2. 将socket()返回值和本地的IP端口绑定到一起
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(10000); // 大端端口
  // INADDR_ANY代表本机的所有IP, 假设有三个网卡就有三个IP地址
  // 这个宏可以代表任意一个IP地址
  // 这个宏一般用于本地的绑定操作
  addr.sin_addr.s_addr = INADDR_ANY; // 这个宏的值为0 == 0.0.0.0
                                     //    inet_pton(AF_INET, "192.168.237.131",
                                     //    &addr.sin_addr.s_addr);
  socket_.setServerAddr(addr);
  int ret = socket_.bindSocket();
  
  if (ret == -1) {
    perror("bind失败");
    exit(0);
  }

  // 3. 设置监听
  ret = socket_.listenSocket();
  
  if (ret == -1) {
    perror("listen操作失败");
    exit(0);
  }

  // 4. 阻塞等待并接受客户端连接
  struct sockaddr_in cliaddr;
  socklen_t client = sizeof(cliaddr);
  int cfd = socket_.acceptSocket();
  // 5. 和客户端通信
  while (1) {
    // 接收数据
    char buf[1024];
    memset(buf, 0, sizeof(buf));

    int len = socket_.readSocket(buf);
    
    
    if (len == 0) {
      break;
    }
    if (len < 0) {
      break;
    }
  }
  return 0;
}
