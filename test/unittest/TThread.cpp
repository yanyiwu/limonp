#include "gtest/gtest.h"
#include "Thread.hpp"
using namespace limonp;

TEST(IThread, Test1) {
  class ThreadHandle: public IThread {
   public:
    ThreadHandle():num(1) {}
    virtual ~ThreadHandle() {}
   private:
   public:
    virtual void run() {
      ASSERT_EQ(num, 1u);
      num = 2;
    }
   public:
    size_t num;
  };
  {
    ThreadHandle thr;
    thr.start();
    thr.join();
    ASSERT_EQ(thr.num, 2u);
  }
  {
    IThread* ptr = new ThreadHandle();
    ptr->start();
    ptr->join();
    delete ptr;
  }
}


