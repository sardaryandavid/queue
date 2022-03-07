#ifndef QUEUE_H
#define QUEUE_H

// Круговая очередь

#define QSIZE 5
#define POISON -19

#include <cstdlib>
#include <assert.h>

struct queue
{
    //[begin][...][tail][...][head]
    int tail;
    int head;
    int* data; 
};

//***************************************

void queueCstr (queue* Queue)
{
    assert (Queue != nullptr);

    Queue->data = (int*) calloc(QSIZE, sizeof(int));

    Queue->tail  = -1;
    Queue->head  = -1;
}

//***************************************

void queueDstr (queue* Queue)
{
    assert (Queue != nullptr);

    free(Queue->data);
}  

//***************************************

int isFull (queue* Queue)
{
    assert (Queue != nullptr);

    return ((Queue->tail == Queue->head + 1) || 
           (Queue->tail == 0 && Queue->head == QSIZE - 1)) ? 1 : 0;
}

// Comm: When we push in first time everything is ok becouse head = tail = -1 and 
// this function returns false

//***************************************

int isEmpty (queue* Queue)
{
    return (Queue->head == -1) ? 1 : 0;
}

//***************************************

// this function returns the amount of elements

int qElemAm (queue* Queue)
{
    assert (Queue != nullptr);
    
    printf("head: %d, tail: %d\n", Queue->head, Queue->tail);

    return (Queue->head > Queue->tail) ? (Queue->head - Queue->tail + 1) :
                                         ((Queue->head + 1) + (QSIZE - Queue->tail));
}

//***************************************

void qPush (queue* Queue, int val)
{
    assert (Queue != nullptr);
    assert (!isFull(Queue));
    
    if (Queue->tail == -1)
        Queue->tail = 0;

    Queue->head = (Queue->head + 1) % QSIZE;
    *(Queue->data + Queue->head) = val;
}

//***************************************

int qPop (queue* Queue)
{
    assert (Queue != nullptr);
    assert (!isEmpty(Queue));

    int val = Queue->tail; 
    *(Queue->data + Queue->tail) = POISON;
    Queue->tail = (Queue->tail + 1) % QSIZE;

    // Проверяем на то, что очередь пустая

    if (Queue->tail == Queue->head)
    {
        Queue->tail = -1;
        Queue->head = -1;
    }

    return val;
}

//***************************************

void qPrint (queue* Queue)
{
    int queueSize = qElemAm(Queue);

    printf("elements: %d\n", queueSize);

    for (int i = Queue->tail; i <= queueSize; ++i)
    {
        printf("Queue[%d] = %d\n", i, *(Queue->data + i));
    }
}

// 

#endif