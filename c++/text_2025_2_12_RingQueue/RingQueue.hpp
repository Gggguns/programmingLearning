#pragma once
#include <iostream>
#include <vector>
#include <pthread.h>
#include <semaphore.h>

const static int defaultnum = 5;

template <class T>
class RingQueue
{
public:
    RingQueue(int cap = defaultnum)
    :ringqueue_(cap), cap_(cap), c_step_(0), p_step_(0) 
    {
        sem_init(&cdata_sem_, 0, 0);
        sem_init(&pspace_sem_, 0, cap_);

        pthread_mutex_init(&c_mutex_, nullptr);
        pthread_mutex_init(&p_mutex_, nullptr);
    }
    //信号量PV操作
    void P(sem_t &sem)
    {
        sem_wait(&sem);
    }
    void V(sem_t &sem)
    {
        sem_post(&sem);
    }

    // 加锁解锁
    void Lock(pthread_mutex_t &mutex)
    {
        pthread_mutex_lock(&mutex);
    }
    void Unlock(pthread_mutex_t &mutex)
    {
        pthread_mutex_unlock(&mutex);
    }
    
    // 生产
    void Push(const T &in)
    {
        // 申请信号量应该放在加锁之前，还是之后
        P(pspace_sem_);

        // 多个生产者会对同一个下标进行竞争，需要加锁保护
        Lock(p_mutex_);
        ringqueue_[p_step_] = in;

        // 位置后移，维持环形特性
        p_step_++;
        p_step_ %= cap_;
        Unlock(p_mutex_);

        V(cdata_sem_);
    }
    
    // 消费
    void Pop(T *out)
    {
        P(cdata_sem_);

        Lock(c_mutex_);
        *out = ringqueue_[c_step_];

        // 位置后移，维持环形特性
        c_step_++;
        c_step_ %= cap_;
        Unlock(c_mutex_);

        V(pspace_sem_);
    }

    ~RingQueue()
    {
        sem_destroy(&cdata_sem_);
        sem_destroy(&pspace_sem_);

        pthread_mutex_destroy(&c_mutex_);
        pthread_mutex_destroy(&p_mutex_);
    }
private:
    std::vector<T> ringqueue_; // 循环队列
    int cap_; // 循环队列的容量

    int c_step_; // 消费者下标
    int p_step_; // 生产者下标

    sem_t cdata_sem_; // 消费者会关注数据资源
    sem_t pspace_sem_; // 生产者会关注的空间资源
    
    // 生产者和消费者，用同一把锁，还是各用各的？
    // 各用各的，除去队列为满为空的时候，消费者和生产者访问的位置不同
    pthread_mutex_t c_mutex_;
    pthread_mutex_t p_mutex_;
};