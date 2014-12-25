#include "gtest/gtest.h"
#include "ThreadPool.hpp"
using namespace Limonp;

//static void addOne(void * data)
//{
//    size_t * i = (size_t *) data;
//    (*i) ++;
//}

class Task: public ITask {
 public:
  Task(size_t& i): i_(i) {
  }
 public:
  size_t& i_;
 public:
  virtual void run() {
    i_++;
  }
};


TEST(ThreadPool, Test1) {
  const size_t threadNum = 2;
  const size_t queueMaxSize = 4;
  vector<size_t> numbers(6);
  //vector<Task*> tasks(numbers.size());
  //for(size_t i = 0; i < tasks.size() ; i++)
  //{
  //    tasks[i] = new Task(numbers[i]);
  //}
  {
    ThreadPool threadPool(threadNum, queueMaxSize);
    threadPool.start();
    for(size_t i = 0; i < numbers.size(); i ++) {
      numbers[i] = i;
      threadPool.add(CreateTask<Task, size_t& >(numbers[i]));
    }
  }
  //for(size_t i = 0 ; i < tasks.size(); i++)
  //{
  //    delete tasks[i];
  //}

  for(size_t i = 0; i < numbers.size(); i++) {
    ASSERT_EQ(i + 1, numbers[i]);
  }
  //threadPool.join();
  //for(size_t i = 0 ; i < numbers.size(); i++)
  //{
  //}
}


