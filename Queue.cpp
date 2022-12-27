#include <iostream>
#include "Queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue()
{
    front = NULL;
    count = 0;
}
template <typename T>
bool Queue<T>::queueIsEmpty()
{
    return count == 0;
}

template <typename T>
int Queue<T>::queueLength()
{
    return count;
}

template <typename T>
void Queue<T>::enqueue(T data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (front == NULL)
    {
        front = node;
        rear = front;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
    count++;
}

template <typename T>
void Queue<T>::dequeue(T &data)
{
    if (queueIsEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        data = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }
}

template <typename T>
void Queue<T>::makeQueueEmpty()
{
    while (front != NULL)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }
}

template <typename T>
Queue<T>::~Queue()
{
    makeQueueEmpty();
}

template <typename T>
void Queue<T>::getFront(T &data)
{
    data = front->data;
}