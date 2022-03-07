#include <stdio.h>

#include "queue.h"

int main()
{
    queue Queue;
    queueCstr (&Queue);
    // Так не работает 
    // queue* Queue;
    // queueCstr (&ueue);
    
    qPush (&Queue, 5);
    qPush (&Queue, 4);
    qPush (&Queue, 10);
    qPush (&Queue, 17);
    qPush (&Queue, 13);
    qPop(&Queue);

    qPrint(&Queue);
    
    queueDstr (&Queue);

    return 0;
}

// makefile 