#ifndef Queue_H
#define Queue_H

class Queue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
    };
    Node *front, *rear;
    int count;

public:
    Queue();
    ~Queue();
    bool queueIsEmpty();
    void makeQueueEmpty();
    int queueLength();
    void enqueue(int);
    void dequeue(int &);
};

#include "Queue.cpp"
#endif
