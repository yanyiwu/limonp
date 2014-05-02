#include "gtest/gtest.h"
#include "std_outbound.hpp"
#include "MutexLock.hpp"

using namespace Limonp;

const size_t THREAD_SUM = 3;
const size_t FOR_SIZE = 3;

vector<size_t> res;

struct PthreadInfo
{
    size_t id;
    pthread_t pthread_id;
    MutexLock* ptMutexLock;
};

void* workerNoLocked(void * arg)
{
    for(size_t i = 0; i < FOR_SIZE; i ++)
    {
        //cout << ptInfo->id << ':' << i << endl;
        res.push_back(i);
        usleep(100 * i);
    }
    return NULL;
}

void* workerLocked(void * arg)
{
    PthreadInfo * ptInfo = (PthreadInfo *) arg;
    MutexLockGuard lock(*ptInfo->ptMutexLock);
    for(size_t i = 0; i < FOR_SIZE; i ++)
    {
        //cout << ptInfo->id << ':' << i << endl;
        res.push_back(i);
        usleep(100 * i);
    }
    return NULL;
}

class ThreadsNoLocked
{
    private:
        MutexLock _mutex;
        vector<PthreadInfo> _pthreadInfos;
    public:
        ThreadsNoLocked(size_t threadSum): _pthreadInfos(threadSum)
        {
            for(size_t i = 0; i < _pthreadInfos.size(); i++)
            {
                _pthreadInfos[i].id = i;
                _pthreadInfos[i].ptMutexLock = &_mutex;
                CHECK(pthread_create(&_pthreadInfos[i].pthread_id, NULL, workerNoLocked, &_pthreadInfos[i]));
            }
        }
        ~ThreadsNoLocked(){}
    public:
        void start()
        {
            for(size_t i = 0; i < _pthreadInfos.size(); i++)
            {
                CHECK(pthread_join(_pthreadInfos[i].pthread_id, NULL));
            }
        }
};

class ThreadsLocked
{
    private:
        MutexLock _mutex;
        vector<PthreadInfo> _pthreadInfos;
    public:
        ThreadsLocked(size_t threadSum): _pthreadInfos(threadSum)
        {
            for(size_t i = 0; i < _pthreadInfos.size(); i++)
            {
                _pthreadInfos[i].id = i;
                _pthreadInfos[i].ptMutexLock = &_mutex;
                CHECK(pthread_create(&_pthreadInfos[i].pthread_id, NULL, workerLocked, &_pthreadInfos[i]));
            }
        }
        ~ThreadsLocked(){}
    public:
        void start()
        {
            for(size_t i = 0; i < _pthreadInfos.size(); i++)
            {
                CHECK(pthread_join(_pthreadInfos[i].pthread_id, NULL));
            }
        }
};

TEST(MutexLock, Test1)
{
    string str;
    ThreadsNoLocked noLock(THREAD_SUM);
    res.clear();
    noLock.start();
    ASSERT_EQ(str << res, "[\"0\", \"0\", \"0\", \"1\", \"1\", \"1\", \"2\", \"2\", \"2\"]");
    ThreadsLocked locked(THREAD_SUM);
    res.clear();
    locked.start();
    ASSERT_EQ(str << res,  "[\"0\", \"1\", \"2\", \"0\", \"1\", \"2\", \"0\", \"1\", \"2\"]");
}


