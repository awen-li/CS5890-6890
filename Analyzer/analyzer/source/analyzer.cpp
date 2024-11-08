#include "analyzer.h"
#include <Queue.h>
#include <ctrace/Event.h>

void* ReadQueueMain (void *Para)
{
    /* init event queue */
    InitQueue(MEMMOD_SHARE);

    while (1)
    {
        unsigned QSize = QueueSize ();
        while (QSize != 0)
        {
            QNode *QN = ::FrontQueue ();
            if (QN == NULL || QN->IsReady == FALSE)
            {

                QSize = ::QueueSize ();  
                continue;
            }

            //
            // your code here, update UnCoveredFuncs
            //

            QSize = QueueSize ();
        }   
    }

    pthread_exit ((void*)0);
}

void Analyzer::StartReadQueue ()
{
    pthread_t Tid = 0;
    int Ret = pthread_create(&Tid, NULL, ReadQueueMain, NULL);
    if (Ret != 0)
    {
        fprintf (stderr, "pthread_create for ReadQueueMain fail, Ret = %d\r\n", Ret);
        exit (0);
    }

    return;
}


string Analyzer::GetUncoveredFuncs ()
{
    //
    // iterate UnCoveredFuncs to generate the uncovered function list
    // 
    return "";
}