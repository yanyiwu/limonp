#ifndef LIMONP_BOUNDED_QUEUE_HPP
#define LIMONP_BOUNDED_QUEUE_HPP

#include <vector>
#include <fstream>
#include <cassert>

namespace Limonp
{
    using namespace std;
    template<class T>
        class BoundedQueue
        {
            private:
                size_t _head;
                size_t _tail;
                size_t _size;
                const size_t _capacity;
                vector<T> _circular_buffer;
            public:
                explicit BoundedQueue(size_t capacity): _capacity(capacity), _circular_buffer(capacity)
                {
                    _head = 0;
                    _tail = 0;
                    _size = 0;
                    assert(_capacity);
                }
                ~BoundedQueue(){}
            public:
                void clear()
                {
                    _head = 0;
                    _tail = 0;
                    _size = 0;
                }
                bool empty() const
                {
                    return !_size;
                }
                bool full() const
                {
                    return _capacity == _size;
                }
                size_t size() const
                {
                    return _size;
                }
                size_t capacity() const
                {
                    return _capacity;
                }

                void push(const T& t)
                {
                    assert(!full());
                    _circular_buffer[_tail] = t;
                    _tail = (_tail + 1) % _capacity;
                    _size ++;
                }

                T pop()
                {
                    assert(!empty());
                    size_t oldPos = _head;
                    _head = (_head + 1) % _capacity;
                    _size --;
                    return _circular_buffer[oldPos];
                }

        };
}

#endif
