/*
https://github.com/chenshuo/muduo/blob/master/muduo/base/BlockingQueue.h
*/

#ifndef LIMONP_BLOCKINGQUEUE_HPP
#define LIMONP_BLOCKINGQUEUE_HPP

#include <queue>
#include "BoundedQueue.hpp"
#include "Condition.hpp"

namespace Limonp
{
    template<class T>
        class BlockingQueue: NonCopyable
        {
            public:
                BlockingQueue()
                    : _mutex(), _notEmpty(_mutex), _queue()
                {
                }

                void push(const T& x)
                {
                    MutexLockGuard lock(_mutex);
                    _queue.push(x);
                    _notEmpty.notify(); // wait morphing saves us
                }

                T pop()
                {
                    MutexLockGuard lock(_mutex);
                    // always use a while-loop, due to spurious wakeup
                    while (_queue.empty())
                    {
                        _notEmpty.wait();
                    }
                    assert(!_queue.empty());
                    T front(_queue.front());
                    _queue.pop();
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

    template<typename T>
        class BoundedBlockingQueue : NonCopyable
        {
            public:
                explicit BoundedBlockingQueue(size_t maxSize)
                    : _mutex(),
                    _notEmpty(_mutex),
                    _notFull(_mutex),
                    _queue(maxSize)
                {}

                void push(const T& x)
                {
                    MutexLockGuard lock(_mutex);
                    while (_queue.full())
                    {
                        _notFull.wait();
                    }
                    assert(!_queue.full());
                    _queue.push(x);
                    _notEmpty.notify();
                }

                T pop()
                {
                    MutexLockGuard lock(_mutex);
                    while (_queue.empty())
                    {
                        _notEmpty.wait();
                    }
                    assert(!_queue.empty());
                    T res = _queue.pop();
                    _notFull.notify();
                    return res;
                }

                bool empty() const
                {
                    MutexLockGuard lock(_mutex);
                    return _queue.empty();
                }

                bool full() const
                {
                    MutexLockGuard lock(_mutex);
                    return _queue.full();
                }

                size_t size() const
                {
                    MutexLockGuard lock(_mutex);
                    return _queue.size();
                }

                size_t capacity() const
                {
                    return _queue.capacity();
                }

            private:
                mutable MutexLock          _mutex;
                Condition                  _notEmpty;
                Condition                  _notFull;
                BoundedQueue<T>  _queue;
        };

}

#endif
