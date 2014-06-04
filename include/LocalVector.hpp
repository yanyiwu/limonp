#ifndef LIMONP_LOCAL_VECTOR_HPP
#define LIMONP_LOCAL_VECTOR_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

namespace Limonp
{
    using namespace std;
    const size_t LOCAL_VECTOR_BUFFER_SIZE = 32;
    template <class T>
        class LocalVector
        {
            public:
                typedef T* const_iterator ;
            public:
                LocalVector(): _ptr(_buffer), _size(0), _capacity(LOCAL_VECTOR_BUFFER_SIZE)
                {
                };
                ~LocalVector()
                {
                    if(_ptr != _buffer)
                    {
                        free(_ptr);
                    }
                };
            public:
                T& operator [] (size_t i) 
                {
                    return _ptr[i];
                }
                void push_back(const T& t)
                {
                    if(!full())
                    {
                        _ptr[_size++] = t;
                        return ;
                    }
                    reserve(_capacity * 2);
                    _ptr[_size ++ ] = t;
                }
                void reserve(size_t size) 
                {
                    if(size <= _capacity)
                    {
                        return;
                    }
                    T * next =  (T*)malloc(sizeof(T) * size);
                    assert(next);
                    T * old = _ptr;
                    _ptr = next;
                    memcpy(_ptr, old, sizeof(T) * _capacity);
                    _capacity = size;
                    if(old != _buffer)
                    {
                        free(old);
                    }
                }
                bool full() const
                {
                    return size() == capacity();
                }
                bool empty() const
                {
                    return 0 == size();
                }
                size_t size() const
                {
                    return _size;
                }
                size_t capacity() const
                {
                    return _capacity;
                }
                const_iterator begin() const
                {
                    return _ptr;
                }
                const_iterator end() const
                {
                    return _ptr + _size;
                }
            private:
                T _buffer[LOCAL_VECTOR_BUFFER_SIZE];
                T * _ptr;
                size_t _size;
                size_t _capacity;
        };
}

#endif
