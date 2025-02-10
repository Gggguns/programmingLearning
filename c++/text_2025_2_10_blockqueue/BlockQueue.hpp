#pragma once
#include <iostream>
#include <queue>
#include <unistd.h>
#include <pthread.h>

template<class T>
class BlockQueue
{
public:
    static const int defaultnum = 10;
    BlockQueue(int maxcap = defaultnum):maxcap_(maxcap)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&p_cond_, nullptr);
        pthread_cond_init(&c_cond_, nullptr);
        low_water_ = maxcap_/3;
        high_water_ = maxcap_*2/3;
    }
    // 谁来唤醒线程呢？
    // 生产者只要生产了，就能保证队列里有数据，也就可以唤醒消费者来消费
    // 消费者刚消费了一个数据，肯定能保证，当前有空间，来进行生产。由消费者唤醒生产者
    void push(const T &in)
    {
        pthread_mutex_lock(&mutex_);
        while(q_.size() == maxcap_)
        {
            //如果线程被误唤醒了呢？
            pthread_cond_wait(&p_cond_, &mutex_); // 1.调用的时候，自动释放锁 2.唤醒返回的时候，重新持有锁
        }
        // 1.队列没满 2.被唤醒
        q_.push(in); // 你想生产，就直接能生产吗？ 不一定，你得先确保生产条件满足
        if(q_.size() > high_water_)pthread_cond_signal(&c_cond_); 
        pthread_mutex_unlock(&mutex_);
    }
    T pop()
    {
        pthread_mutex_lock(&mutex_);
        while(q_.size() == 0) // 做到防止被伪唤醒的情况
        { 
            // 伪唤醒情况
            pthread_cond_wait(&c_cond_, &mutex_);
        }
        T out = q_.front(); // 你想消费，就直接能消费吗？ 不一定，你得先确保消费条件满足
        q_.pop();
        if(q_.size() < low_water_)pthread_cond_signal(&p_cond_);
        pthread_mutex_unlock(&mutex_);

        return out;
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&p_cond_);
        pthread_cond_destroy(&c_cond_);
    }
private:
    std::queue<T> q_; // 共享资源，q被当作整体使用的，q只有一份，加锁。但是共享资源也可以被看成多份
    int maxcap_; // 极值
    pthread_mutex_t mutex_;
    // 生产和消费能不能使用同一个条件变量？ 不能
    pthread_cond_t p_cond_; // 生产队列
    pthread_cond_t c_cond_; // 消费队列

    int low_water_;
    int high_water_;
};