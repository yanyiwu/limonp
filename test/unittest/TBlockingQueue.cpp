#include "gtest/gtest.h"
#include "BlockingQueue.hpp"

using namespace Limonp;

class CBlockingQueueTest1
{
    private:
        vector<pthread_t> _pthreads;
    public:
        static void* workerLocked(void * arg)
        {
            cout << __LINE__ << endl;
            BlockingQueue<size_t> * res = (BlockingQueue<size_t> *)arg;
            size_t t = res->pop();
            cout << __LINE__ << endl;
            res->push(t);
            return NULL;
        }
    public:
        CBlockingQueueTest1(const size_t threadSum, void* arg): _pthreads(threadSum)
        {
            for(size_t i = 0; i < _pthreads.size(); i++)
            {
                CHECK(pthread_create(&_pthreads[i], NULL, workerLocked, arg));
            }
        }
        ~CBlockingQueueTest1()
        {}
    public:
        void wait()
        {
            for(size_t i = 0; i < _pthreads.size(); i++)
            {
                CHECK(pthread_join(_pthreads[i], NULL));
            }
        }
        
};

TEST(BlockingQueue, Test1)
{
    size_t threadnum = 3;
    BlockingQueue<size_t> res;
    CBlockingQueueTest1 obj(threadnum, &res);
    cout << __LINE__ << endl;
    //sleep(1);
    cout << __LINE__ << endl;
    res.push(1);
    cout << __LINE__ << endl;
    obj.wait();
    cout << __LINE__ << endl;
    cout << res.pop() << endl;
}


