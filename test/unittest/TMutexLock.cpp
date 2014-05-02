#include "gtest/gtest.h"
#include "MutexLock.hpp"

using namespace Limonp;

struct PthreadInfo
{
    size_t id;
    pthread_t pthread_id;
    MutexLock* ptMutexLock;
};

void* worker(void * arg)
{
    PthreadInfo * ptInfo = (PthreadInfo *) arg;
    //MutexLockGuard lock(*ptInfo->ptMutexLock);
    for(size_t i = 0; i < 3; i ++)
    {
        cout << ptInfo->id << ':' << i << endl;
        usleep(100*i);
    }

    return NULL;
}

class TMutexLock
{
    private:
        MutexLock _mutex;
        vector<PthreadInfo> _pthreadInfos;
    public:
        TMutexLock(size_t threadSum): _pthreadInfos(threadSum)
        {
            for(size_t i = 0; i < _pthreadInfos.size(); i++)
            {
                _pthreadInfos[i].id = i;
                _pthreadInfos[i].ptMutexLock = &_mutex;
                CHECK(pthread_create(&_pthreadInfos[i].pthread_id, NULL, worker, &_pthreadInfos[i]));
            }
        }
        ~TMutexLock(){}
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
    size_t threadSum = 3;
    TMutexLock tMutex(threadSum);
    tMutex.start();
}


