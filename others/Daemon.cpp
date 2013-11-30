#include "Daemon.h"

namespace Husky
{

    IWorkHandler * Daemon::m_pHandler;
    int Daemon::m_nChildPid = 0;

    void Daemon::sigMasterHandler(int sig)
    {        
        kill(m_nChildPid,SIGUSR1);
        LogDebug("master = %d sig child =%d!",getpid(),m_nChildPid);

    }

    void Daemon::sigChildHandler(int sig)
    {        
        if (sig == SIGUSR1)
        {
            m_pHandler->dispose();
            LogDebug("master = %d signal accept current pid =%d!",getppid(),getpid());
        }

    }

}


