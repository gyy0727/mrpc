/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-10-22 17:00:33
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-11-21 15:14:53
 * @FilePath: /桌面/src/Thread.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "../include/Thread.h"
#include "../include/ThreadPool.h"
// 自定义线程ID
int Thread_::generalId = 0;
// 创建线程
void Thread_::start()
{
    std::cout << "线程启动"
              << " ID: " << this->threadId_ << std::endl;
    std::thread t1(func_, threadId_);
    t1.detach();
}
// 初始化进程
Thread_::Thread_(taskfunc func_) : func_(func_), threadId_(generalId++)
{
}

// 获取自定义进程ID
int Thread_::getId()
{
    return this->threadId_;
}
Thread_::~Thread_()
{
    std::cout << "线程析构"
              << " ID: " << this->threadId_ << std::endl;
}