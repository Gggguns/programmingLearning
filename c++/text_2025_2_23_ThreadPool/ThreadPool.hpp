#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <pthread.h>
#include <ctime>
#include <sys/types.h>
#include <unistd.h>

struct ThreadInfo
{
    pthread_t tid;
    std::string name;
};

const static int defaultnum = 5;

template <class T>
class ThreadPool
{
private:
    // 加锁解锁
    void Lock()
    {
        pthread_mutex_lock(&mutex_);
    }
    void Unlock()
    {
        pthread_mutex_unlock(&mutex_);
    }
    // 判空
    bool IsQueueEmpty()
    {
        return tasks_.empty();
    }
    // 唤醒休眠
    void WakeUp()
    {
        pthread_cond_signal(&cond_);
    }
    void ThreadSleep()
    {
        pthread_cond_wait(&cond_, &mutex_);
    }
    // 获取线程名字
    std::string GetThreadName(pthread_t tid)
    {
        for(const auto &ti : threads_)
        {
            if(ti.tid == tid)return ti.name;
        }
        return "None";
    }
public:

    static void *HandlerTask(void *args)
    {
        ThreadPool<T> *tp = static_cast<ThreadPool<T>*>(args);
        std::string name = tp->GetThreadName(pthread_self());
        while(true)
        {
            tp->Lock();

            while(tp->IsQueueEmpty())
            {
                tp->ThreadSleep();
            }

            T t = tp->Pop();

            tp->Unlock();
            t();
            std::cout << name << " run, " << "result: " << t.GetResult() << std::endl;
        }
    }

    void Start()
    {
        int num = threads_.size();
        for(int i = 0; i < num; i++)
        {
            threads_[i].name = "thread-" + std::to_string(i+1);
            // 点和取地址哪个优先级更高？取地址
            pthread_create(&(threads_[i].tid), nullptr, HandlerTask, this);
        }
    }
    T Pop()
    {
        T t = tasks_.front();
        tasks_.pop();
        return t;
    }
    void Push(const T& in)
    {
        Lock();
        tasks_.push(in);
        WakeUp();
        Unlock();
    }
    static ThreadPool<T> *GetInstance()
    {
        // 双重判断
        if(nullptr == tp_)
        {    
            pthread_mutex_lock(&lock_);
            if(nullptr == tp_)
            {
                std::cout << "log: singleton create done first!" << std::endl;
                tp_ = new ThreadPool<T>();
            }
            pthread_mutex_unlock(&lock_);
        }

        return tp_;
    }
private:
    ThreadPool(int num = defaultnum):threads_(num)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }
    ~ThreadPool()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }
    ThreadPool(const ThreadPool<T>&) = delete;
    const ThreadPool<T>& operator()(const ThreadPool<T>&) = delete;
private:
    std::vector<ThreadInfo> threads_;
    std::queue<T> tasks_;

    pthread_mutex_t mutex_;
    pthread_cond_t cond_;

    static ThreadPool<T> *tp_;
    static pthread_mutex_t lock_;
};

template<class T>
ThreadPool<T> *ThreadPool<T>::tp_ = nullptr;

template<class T>
pthread_mutex_t ThreadPool<T>::lock_ = PTHREAD_MUTEX_INITIALIZER;