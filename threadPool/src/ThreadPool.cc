/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-10-22 17:00:46
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-10-26 17:12:14
 * @FilePath: /桌面/src/ThreadPool.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "../include/ThreadPool.h"
#include "../include/Thread.h"

void ThreadPool_::threadFunc(int threadId)
{
    for (;;)
    {
        std::unique_lock<std::mutex> lock(lock_task);
        if (!notEmpty_.wait_for(lock, std::chrono::seconds(1), [&]() -> bool
                                { return task_.size() > 0; }))
        {
            std::cout << "任务队列为空"
                      << "线程ID:" << threadId << "无法取得任务 " << std::endl;
            return;
        }
        std::function<void()> task_exe = task_.front();
        task_exe();
        task_.pop();

        notFull_.notify_all();
    }
}
void ThreadPool_::start()
{
    for (int i = 0; i < MAXTHREADSIZE; i++)
    {
        auto ptr = std::make_unique<Thread_>(std::bind(&ThreadPool_::threadFunc, this, std::placeholders::_1));
        int threadId = ptr->getId();
        threadsMap_.emplace(threadId, std::move(ptr));
    }
    for (int i = 0; i < MAXTHREADSIZE; i++)
    {
        threadsMap_[i]->start();
    }
}

void ThreadPool_::setModel(PoolModel mode)
{
    this->mode = mode;
}
