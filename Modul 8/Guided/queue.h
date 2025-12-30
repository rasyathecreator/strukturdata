#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(queue &Q);

bool isEmpty(queue Q);

bool isFull(queue Q);

void enqueue(queue &Q, int x);

int dequeue(queue &Q);

void printInfo(queue Q);

#endif