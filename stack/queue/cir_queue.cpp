/*
 * =====================================================================================
 *
 *       Filename:  cir_queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2018 04:57:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
typedef struct _queue {
    int front; /*  dequeue from front */
    int rear;  /*  enqueue to the rear  */
    int *val;
    int size;
} QUEUE;


QUEUE *init_queue(int size) {
    QUEUE *Queue = (QUEUE *)malloc (sizeof(QUEUE));
    if (Queue == NULL) return NULL;

    Queue->val  = (int *)malloc(size *(sizeof(int)));
    if (Queue->val == NULL)  return NULL;
    Queue->front = Queue->rear = -1;
    Queue->size = size;

    return Queue;
}


bool is_empty(QUEUE *Queue) {
    if (Queue == NULL) return true;

    if (Queue->front == -1)  {
        return true;
    }
    return false;
}

bool is_full(QUEUE *que) {
    int next = que->rear + 1;
    if (next >= que->size) next =0; /*  wrap around to 0 */
    if (next == que->front) {
        return true;
    }
    return false;
}


bool enqueue( QUEUE *que, int val) {
    if (is_full(que)) return false;
    if (is_empty(que)) {
        que->rear = que->front = 0;
    } else {
        que->rear++; 
        if (que->rear >=que->size) {/*  then wrap around */
            que->rear = 0;
        }
    }
    que->val[que->rear]=val;
    return true;
}

bool  dequeue(QUEUE *que, int *val) {
    if(is_empty(que)) return false;

    *val = que->val[que->front];
    if (que->rear == que->front) { /*  last element */
        que->rear = que->front = -1;
    } else {
        que->front++;
        if (que->front == que->size) {
            que->front = 0; /*  wrap aound */

        }
    }
    return true;
}

int main (void) {
    QUEUE *q = init_queue(4);
    enqueue(q, 2);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    int val =0;
    while (dequeue(q, &val)) {
        std::cout << val << "   \n";
    }
    std::cout << "que is empty \n" ;

}

