#ifndef LIMONP_THREAD_HPP
#define LIMONP_THREAD_HPP

#include "HandyMacro.hpp"
#include "NonCopyable.hpp"

namespace Limonp
{
    class Thread: NonCopyable
    {
        private:
            pthread_t thread_;
        public:
            Thread()
            {
            }
            virtual ~Thread()
            {
                //TODO
                //pthread_exit or pthread_datach
            };
        public:
            virtual void run() = 0;
            void start()
            {
                LIMONP_CHECK(pthread_create(&thread_, NULL, worker_, this));
            }
            void join()
            {
                LIMONP_CHECK(pthread_join(thread_, NULL));
            }
        private:
            static void * worker_(void * data)
            {
                Thread * ptr = (Thread* ) data;
                ptr->run();
                return NULL;
            }
    };
}

#endif
