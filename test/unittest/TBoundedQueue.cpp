#include "BoundedQueue.hpp"
#include "gtest/gtest.h"

using namespace Limonp;

TEST(BoundedQueue, Test1)
{
    const size_t size = 3;
    BoundedQueue<size_t> que(size);
    ASSERT_EQ(que.capacity(), size);
    for(size_t i = 0; i < que.capacity(); i++)
    {
        que.push(i);
        ASSERT_EQ(que.size(), i + 1);
    }
    ASSERT_TRUE(que.full());
    for(size_t i = 0; que.size(); i++)
    {
        ASSERT_EQ(que.pop(), i);
    }
    ASSERT_TRUE(que.empty());

    //second time
    for(size_t i = 0; i < que.capacity(); i++)
    {
        que.push(i);
        ASSERT_EQ(que.size(), i + 1);
    }
    ASSERT_TRUE(que.full());
    for(size_t i = 0; que.size(); i++)
    {
        ASSERT_EQ(que.pop(), i);
    }
    ASSERT_TRUE(que.empty());
}

