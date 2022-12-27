#ifndef Queue_H
#define Queue_H

template <typename T>
class Queue
{
private:
    class Node
    {
    public:
        T data;
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
    void enqueue(T);
    void dequeue(T &);
    void getFront(T &)
};

#include "Queue.cpp"
#endif
