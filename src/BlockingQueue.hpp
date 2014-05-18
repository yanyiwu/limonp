/*
https://github.com/chenshuo/muduo/blob/master/muduo/base/BlockingQueue.h
*/

#ifndef LIMONP_BLOCKINGQUEUE_HPP
#define LIMONP_BLOCKINGQUEUE_HPP

#include <queue>
#include "Condition.hpp"

namespace Limonp
{

    template<class T>
        class BlockingQueue: public NonCopyable
        {
            public:
                BlockingQueue()
                    : _mutex(), _notEmpty(_mutex), _queue()
                {
                }

                void push(const T& x)
                {
                    cout << __LINE__ << endl;
                    MutexLockGuard lock(_mutex);
                    cout << __LINE__ << endl;
                    _queue.push(x);
                    cout << __LINE__ << endl;
                    _notEmpty.notify(); // wait morphing saves us
                    cout << __LINE__ << endl;
                }

                T pop()
                {
                    cout << __LINE__ << endl;
                    MutexLockGuard lock(_mutex);
                    cout << __LINE__ << endl;
                    // always use a while-loop, due to spurious wakeup
                    while (_queue.empty())
                    {
                    cout << __LINE__ << endl;
                        _notEmpty.wait();
                    cout << __LINE__ << endl;
                    }
                    cout << __LINE__ << endl;
                    assert(!_queue.empty());
                    cout << __LINE__ << endl;
                    T front(_queue.front());
                    cout << __LINE__ << endl;
                    _queue.pop();
                    cout << __LINE__ << endl;
                    return front;
                }

                size_t size() const
                {
                    MutexLockGuard lock(_mutex);
                    return _queue.size();
                }
                bool empty() const
                {
                    return size() == 0;
                }

            private:
                mutable MutexLock _mutex;
                Condition         _notEmpty;
                std::queue<T>     _queue;
        };

}

#endif
