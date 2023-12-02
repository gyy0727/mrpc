/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-10-22 16:57:20
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-10-24 12:12:06
 * @FilePath: /桌面/include/ThreadPool.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#pragma once
#include <iostream>
#include <functional>
#include <thread>
#include "Thread.h"
#include <chrono>
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <future>
#include <map>
const int MAXTHREADSIZE = 8;
const int MAXTASKSIZE = 1024; // fix模式下线程池线程数量
class Thread_;
// 线程池模式
enum class PoolModel
{
	MODE_FIXED,	 // 固定线程池数量
	MODE_CACHED, // 线程动态增长
};
class ThreadPool_
{
public:
	using Task_ = std::function<void()>;
	ThreadPool_() = default;
	~ThreadPool_() = default;
	// 创建线程//开启线程池(传入任务,执行线程)
	void start();
	// 设置线程池模式
	void setModel(PoolModel mode);

	// 提交任务
	template <class T, class... Args>
	auto sumTask(T func, Args... args) -> std::future<decltype(func(args...))>
	{
		// 打包任务
		using RTtype = decltype(func(args...));
		auto task = std::make_shared<std::packaged_task<RTtype()>>(std::bind(std::forward<T>(func), std::forward<Args>(args)...));
		std::future<RTtype> result = task->get_future();
		std::unique_lock<std::mutex> lock(lock_task);
		if (!notFull_.wait_for(lock, std::chrono::seconds(1), [&]() -> bool
							   { return task_.size() < MAXTASKSIZE; }))
		{
			std::cout << "任务队列已满" << std::endl;
			auto task = std::make_shared<std::packaged_task<RTtype()>>([]() -> RTtype
																	   { return RTtype(); });
			(*task)();

			return task->get_future();
		}
		//将打包好的任务加入任务队列
		task_.emplace([task]()
					  { (*task)(); });
		//通知其他线程,任务队列不为空
		notEmpty_.notify_all();
		return result;
	}
	// 回收线程
	// 线程函数
	void threadFunc(int threadId);

private:
	std::unordered_map<int, std::unique_ptr<Thread_>> threadsMap_; // 线程列表
	std::queue<Task_> task_;//任务队列
	PoolModel mode;//线程池模式
	std::mutex lock_task;//获取任务列表的锁
	std::condition_variable notFull_;  // 表示任务队列不满
	std::condition_variable notEmpty_; // 表示任务队列不空
	std::condition_variable exitCond_; // 等到线程资源全部回收
};
