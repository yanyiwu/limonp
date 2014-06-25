#include "gtest/gtest.h"
#include "ThreadPool.hpp"
using namespace Limonp;

static void addOne(void * data)
{
    size_t * i = (size_t *) data;
    (*i) ++;
}

TEST(ThreadPool, Test1)
{
    const size_t threadNum = 5;
    const size_t queueMaxSize = 10;
    ThreadPool threadPool(threadNum, queueMaxSize);
    threadPool.start();
    vector<size_t> numbers(30);
    for(size_t i = 0; i < numbers.size(); i ++)
    {
        numbers[i] = i;
        Task task(addOne, &numbers[i]);
        threadPool.push(task);
    }
    threadPool.wait();
    for(size_t i = 0; i < numbers.size(); i++)
    {
        ASSERT_EQ(i + 1, numbers[i]);
    }
    //threadPool.join();
    //for(size_t i = 0 ; i < numbers.size(); i++)
    //{
    //}
}


