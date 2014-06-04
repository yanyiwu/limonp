#include "gtest/gtest.h"
#include <vector>
#include "BlockingQueue.hpp"

using namespace Limonp;
using namespace std;

class CBlockingQueueTest1
{
    private:
        vector<pthread_t> _pthreads;
    public:
        static void* workerLocked(void * arg)
        {
            BlockingQueue<size_t> * res = (BlockingQueue<size_t> *)arg;
            size_t t = res->pop();
            res->push(t);
            return NULL;
        }
    public:
        CBlockingQueueTest1(const size_t threadSum, void* arg): _pthreads(threadSum)
        {
            for(size_t i = 0; i < _pthreads.size(); i++)
            {
                LIMONP_CHECK(pthread_create(&_pthreads[i], NULL, workerLocked, arg));
            }
        }
        ~CBlockingQueueTest1()
        {}
    public:
        void wait()
        {
            for(size_t i = 0; i < _pthreads.size(); i++)
            {
                LIMONP_CHECK(pthread_join(_pthreads[i], NULL));
            }
        }
        
};

class CBlockingQueueTest2
{
    public:
        static void * thread_pop(void * arg)
        {
            BlockingQueue<size_t> * res = (BlockingQueue<size_t> *)arg;
            for(size_t i = 0; i < 10; i++)
            {
                res->pop();
            }
            return NULL;
        }
        static void * thread_push(void * arg)
        {
            BlockingQueue<size_t> * res = (BlockingQueue<size_t> *)arg;
            for(size_t i = 0; i < 10; i++)
            {
                usleep(10);
                res->push(i);
            }
            return NULL;
        }
};
class CBoundedBlockingQueueTest3
{
    public:
        static void * thread_pop(void * arg)
        {
            BoundedBlockingQueue<size_t> * res = (BoundedBlockingQueue<size_t> *)arg;
            for(size_t i = 0; i < 10; i++)
            {
                res->pop();
            }
            return NULL;
        }
        static void * thread_push(void * arg)
        {
            BoundedBlockingQueue<size_t> * res = (BoundedBlockingQueue<size_t> *)arg;
            for(size_t i = 0; i < 10; i++)
            {
                usleep(10);
                res->push(i);
            }
            return NULL;
        }
};

TEST(BlockingQueue, Test1)
{
    size_t threadnum = 3;
    BlockingQueue<size_t> res;
    CBlockingQueueTest1 obj(threadnum, &res);
    //sleep(1);
    res.push(1);
    obj.wait();
    ASSERT_EQ(1u, res.size());
    ASSERT_EQ(1u, res.pop());
    
}

TEST(BlockingQueue, Test2)
{
    BlockingQueue<size_t> queue;
    pthread_t pth_push;
    pthread_t pth_pop;
    pthread_create(&pth_push, NULL, CBlockingQueueTest2::thread_push, &queue);
    pthread_create(&pth_pop, NULL, CBlockingQueueTest2::thread_pop, &queue);
    pthread_join(pth_push, NULL);
    pthread_join(pth_pop, NULL);
    ASSERT_TRUE(queue.empty());
}

TEST(BlockingQueue, Test3)
{
    BoundedBlockingQueue<size_t> queue(3);
    pthread_t pth_push;
    pthread_t pth_pop;
    pthread_create(&pth_push, NULL, CBoundedBlockingQueueTest3::thread_push, &queue);
    pthread_create(&pth_pop, NULL, CBoundedBlockingQueueTest3::thread_pop, &queue);
    pthread_join(pth_push, NULL);
    pthread_join(pth_pop, NULL);
    ASSERT_TRUE(queue.empty());
}

