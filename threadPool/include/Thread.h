/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-10-22 16:56:44
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-10-24 11:56:32
 * @FilePath: /����/include/Thread.h
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#pragma once
#include <thread>
#include <iostream>
#include "ThreadPool.h"
#include <functional>
#include <chrono>

class Thread_
{
    //�����������ڽ����̺߳���
    using taskfunc = std::function<void(int)>;

public:
    Thread_(taskfunc func_);
    ~Thread_();
    // �����߳�
    void start();
    //��ȡ�߳�ID
    int getId();

private:
    taskfunc func_;//�̺߳���
    int threadId_;//�߳�ID
    static int generalId;
};
