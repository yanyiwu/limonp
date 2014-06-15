#ifndef LIMONP_THREAD_POOL_HPP
#define LIMONP_THREAD_POOL_HPP

#include "Thread.hpp"
#include "BlockingQueue.hpp"

namespace Limonp
{
    struct Task
    {
        public:
            typedef void (* CallBackFunct)(void*);
        public:
            Task():funct(NULL), param(NULL){}
            Task(CallBackFunct f, void * p): funct(f), param(p){}
        public:
            CallBackFunct funct;
            void * param;
        public:
            void run()
            {
                funct(param);
            }
    };

    class ThreadPool;
    class Worker: public Thread
    {
        private:
            ThreadPool * ptThreadPool_;
        public:
            Worker(ThreadPool* pool): ptThreadPool_(pool)
            {
                assert(ptThreadPool_);
            }
            virtual ~Worker(){}
        public:
            virtual void run();
    };

    class ThreadPool: NonCopyable
    {
        private:
            friend class Worker;
        private:
            vector<Thread*> threads_;
            BoundedBlockingQueue<Task> queue_;
        public:
            ThreadPool(size_t threadNum, size_t queueMaxSize): threads_(threadNum), queue_(queueMaxSize)
            {
                assert(threadNum);
                assert(queueMaxSize);
                for(size_t i = 0; i < threads_.size(); i ++)
                {
                    threads_[i] = new Worker(this);
                }
            }
            ~ThreadPool()
            {
                for(size_t i = 0; i < threads_.size(); i ++)
                {
                    delete threads_[i];
                }
            }
            
        public:
            void start()
            {
                for(size_t i = 0; i < threads_.size(); i++)
                {
                    threads_[i]->start();
                }
            }
            void wait()
            {
                queue_.empty();;
                //TODO
            }
        public:
            void push(const Task& task)
            {
                return queue_.push(task);
            }
        private:
            Task pop_()
            {
                return queue_.pop();
            }
    };
    
    /*
     * 1. seperate declaration and definition to avoid compiler's error about nested incomplete ThreadPool (forward declaration can not solve that)
     * 2. inline is to avoid linking error: "multiple definition of 'typeinfo name for Limonp::Worker'"
     */
    inline void Worker::run() 
    {
        while(true)
        {
            Task task = ptThreadPool_->pop_();
            task.run();
        }
    }
}

#endif
