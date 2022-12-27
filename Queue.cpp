#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
    front = NULL;
    count = 0;
}

bool Queue::queueIsEmpty()
{
    return count == 0;
}

int Queue::queueLength()
{
    return count;
}

void Queue::enqueue(int data)
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

void Queue::dequeue(int &data)
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

void Queue::makeQueueEmpty(){
    while (front!=NULL)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }   
}

Queue::~Queue(){
    makeQueueEmpty();
}