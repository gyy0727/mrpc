/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-19 13:36:37
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-11-22 16:56:14
 * @FilePath: /桌面/smallchat/src/client.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
// client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
int main()
{
    std::cout << "客户端正在运行" << endl;
    // 1. 创建通信的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket");
        exit(0);
    }

    // 2. 连接服务器
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000); // 大端端口
    inet_pton(AF_INET, "192.168.142.131", &addr.sin_addr.s_addr);

    int ret = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("connect");
        exit(0);
    }

    // 3. 和服务器端通信
    int number = 0;
    while (1)
    {
        // 发送数据
        char buf[1024];
        // sprintf(buf, "你好, 服务器...%d\n", number++);
        std::cin >> buf;

        write(fd, buf, strlen(buf) + 1);

        // 接收数据
        memset(buf, 0, sizeof(buf));
        int len = read(fd, buf, sizeof(buf));
        if (len > 0)
        {
            printf("服务器say: %s\n", buf);
        }
        else if (len == 0)
        {
            printf("服务器断开了连接...\n");
            break;
        }
        else
        {
            perror("read");
            break;
        }
        sleep(1); // 每隔1s发送一条数据
    }

    close(fd);

    return 0;
}
