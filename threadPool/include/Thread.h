/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-10-22 16:56:44
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-10-24 11:56:32
 * @FilePath: /桌面/include/Thread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#pragma once
#include <thread>
#include <iostream>
#include "ThreadPool.h"
#include <functional>
#include <chrono>

class Thread_
{
    //函数对象用于接收线程函数
    using taskfunc = std::function<void(int)>;

public:
    Thread_(taskfunc func_);
    ~Thread_();
    // 创建线程
    void start();
    //获取线程ID
    int getId();

private:
    taskfunc func_;//线程函数
    int threadId_;//线程ID
    static int generalId;
};
