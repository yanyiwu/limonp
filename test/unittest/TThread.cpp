#include "gtest/gtest.h"
#include "Thread.hpp"
using namespace Limonp;


TEST(Thread, Test1)
{
    class ThreadDerive: public Thread
    {
        public:
            ThreadDerive():num(1){}
            virtual ~ThreadDerive(){}
        private:
        public:
            virtual void run()
            {
                ASSERT_EQ(num, 1);
                num = 2;
            }
        public:
            size_t num;
    };
    {
        ThreadDerive thr;
        thr.start();
        thr.join();
        ASSERT_EQ(thr.num, 2);
    }
    {
        Thread* ptr = new ThreadDerive();
        ptr->start();
        ptr->join();
        delete ptr;
    }
}


