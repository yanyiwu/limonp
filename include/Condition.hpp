#ifndef LIMONP_CONDITION_HPP
#define LIMONP_CONDITION_HPP

#include "MutexLock.hpp"

namespace limonp {

class Condition : NonCopyable {
 public:
  explicit Condition(MutexLock& mutex)
    : mutex_(mutex) {
    LIMONP_CHECK(!pthread_cond_init(&pcond_, NULL));
  }

  ~Condition() {
    LIMONP_CHECK(!pthread_cond_destroy(&pcond_));
  }

  void Wait() {
    LIMONP_CHECK(!pthread_cond_wait(&pcond_, mutex_.GetPthreadMutex()));
  }

  void Notify() {
    LIMONP_CHECK(!pthread_cond_signal(&pcond_));
  }

  void NotifyAll() {
    LIMONP_CHECK(!pthread_cond_broadcast(&pcond_));
  }

 private:
  MutexLock& mutex_;
  pthread_cond_t pcond_;
}; // class Condition

} // namespace limonp

#endif // LIMONP_CONDITION_HPP
