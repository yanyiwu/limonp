#include "LocalVector.hpp"
#include "StdExtension.hpp"
#include <fstream>
#include "gtest/gtest.h"

using namespace Limonp;

TEST(LocalVector, test1)
{
    LocalVector<size_t> vec;
    ASSERT_EQ(vec.size(), 0);
    ASSERT_EQ(vec.capacity(), LOCAL_VECTOR_BUFFER_SIZE);
    ASSERT_TRUE(vec.empty());
    ASSERT_FALSE(vec.full());
    size_t size = 129;
    for(size_t i = 0; i < size; i++)
    {
        vec.push_back(i);
    }
    ASSERT_EQ(vec.size(), size);
    ASSERT_EQ(vec.capacity(), 256);
    ASSERT_FALSE(vec.empty());
    LocalVector<size_t> vec2(vec);
    ASSERT_EQ(vec2.capacity(), vec.capacity());
    ASSERT_EQ(vec2.size(), vec.size());
}

TEST(LocalVector, test2)
{
    LocalVector<size_t> vec;
    ASSERT_EQ(vec.size(), 0);
    ASSERT_EQ(vec.capacity(), LOCAL_VECTOR_BUFFER_SIZE);
    ASSERT_TRUE(vec.empty());
    ASSERT_FALSE(vec.full());
    size_t size = 1;
    for(size_t i = 0; i < size; i++)
    {
        vec.push_back(i);
    }
    ASSERT_EQ(vec.size(), size);
    ASSERT_EQ(vec.capacity(), LOCAL_VECTOR_BUFFER_SIZE);
    ASSERT_FALSE(vec.empty());
    LocalVector<size_t> vec2;
    vec2 = vec;
    ASSERT_EQ(vec2.capacity(), vec.capacity());
    ASSERT_EQ(vec2.size(), vec.size());
}
