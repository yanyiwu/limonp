#ifndef HUSKY_DAEMON_H_
#define HUSKY_DAEMON_H_
#include "globals.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include "Limonp/logger.hpp"

namespace Husky
{
    using namespace Limonp;

    class IWorkHandler
    {
        public:
            virtual ~IWorkHandler(){}
            virtual bool init() = 0;
            virtual bool dispose() = 0;
            virtual bool run() = 0;
    };

    class Daemon
    {
        public:
            Daemon(IWorkHandler * workHandler, const char* pidFile)
            {
                m_pHandler = workHandler;
                m_pidFile = pidFile;
            }
            ~Daemon(){};
        public:
            bool start()
            {
                string masterPidStr = loadFile2Str(m_pidFile);
                int masterPid = atoi(masterPidStr.c_str());
                if(masterPid)
                {
                    if (kill(masterPid, 0) == 0)
                    {
                        LogError("Another instance exist, ready to quit!");
                        return false;
                    }
                }

                initAsDaemon();

                char buf[64];
                sprintf(buf, "%d", getpid());
                if (!WriteStr2File(m_pidFile,buf ,"w"))
                {
                    LogFatal("Write master pid fail!");
                }

                while(true)
                {
                    pid_t pid = fork();
                    if (0 == pid)// child process do
                    {
                        signal(SIGUSR1, sigChildHandler);
                        signal(SIGPIPE, SIG_IGN);
                        signal(SIGTTOU, SIG_IGN);
                        signal(SIGTTIN, SIG_IGN);
                        signal(SIGTERM, SIG_IGN);
                        signal(SIGINT,  SIG_IGN);
                        signal(SIGQUIT, SIG_IGN);

                        if(!m_pHandler->init())
                        {
                            LogFatal("m_pHandler init failed!");
                            return false;
                        }
                        LogInfo("child process Worker init ok pid[%d]",(int)getpid());

                        if (!m_pHandler->run())
                        {
                            LogError("m_pHandler run finish with failure!");
                            return false;
                        }
                        LogInfo("child process finish ok!");
                        exit(0);
                    }

                    m_nChildPid=pid;
                    int status;
                    pid = wait(&status);
                    if (!isAbnormalExit(pid, status))
                    {
                        LogInfo("child exit normally and Daemon exit");
                        break;
                    }
                }
                return true;
            }
            bool stop()
            {
                string masterPidStr = loadFile2Str(m_pidFile);
                int masterPid = atoi(masterPidStr.c_str());
                if(masterPid)
                {
                    if (kill(masterPid, 0) == 0)
                    {
                        kill(masterPid, SIGTERM);

                        int tryTime = 200;        
                        while (kill(masterPid, 0) == 0 && --tryTime)
                        {
                            sleep(1);            
                        }

                        if (!tryTime && kill(masterPid, 0) == 0)
                        {
                            LogError("Time out shutdown fail!");        
                            return false;
                        }

                        LogInfo("previous daemon pid[%d] shutdown ok.", masterPid);
                        return true;
                    }

                }
                LogError("Another instance doesn't exist, ready to quit!");
                return false;
            }
        public:
            static void initAsDaemon()
            {
                if (fork() > 0)
                  exit(0);
                setsid();

                signal(SIGPIPE, SIG_IGN);
                signal(SIGTTOU, SIG_IGN);
                signal(SIGTTIN, SIG_IGN);
                signal(SIGTERM, sigMasterHandler);
                signal(SIGINT,  sigMasterHandler);
                signal(SIGQUIT, sigMasterHandler);
                signal(SIGKILL, sigMasterHandler);
            }
            static bool isAbnormalExit(int pid, int status)
            {
                bool bRestart = true;
                if (WIFEXITED(status)) //exit()or return 
                {
                    LogDebug("child normal termination, exit pid = %d, status = %d", pid, WEXITSTATUS(status));
                    bRestart = false;
                }
                else if (WIFSIGNALED(status)) //signal方式退出
                {
                    LogError("abnormal termination, pid = %d, signal number = %d%s", pid, WTERMSIG(status),
#ifdef    WCOREDUMP
                                WCOREDUMP(status) ? " (core file generated)" : 
#endif
                                ""); 

                    if (WTERMSIG(status) == SIGKILL)
                    {
                        bRestart = false;
                        LogError("has been killed by user , exit pid = %d, status = %d", pid, WEXITSTATUS(status));
                    }
                }
                else if (WIFSTOPPED(status)) //暂停的子进程退出
                {
                    LogError("child stopped, pid = %d, signal number = %d", pid, WSTOPSIG(status));
                }
                else
                {
                    LogError("child other reason quit, pid = %d, signal number = %d", pid, WSTOPSIG(status));
                }
                return bRestart;
            }
        private:
            static int m_nChildPid;
            static IWorkHandler * m_pHandler;
        private:
            const char* m_pidFile;
        public:
            static void sigMasterHandler(int sig);
            static void sigChildHandler(int sig);
    };
}
#endif
