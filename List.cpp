#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
List<T>::List()
{
    head = NULL;
    cursor = NULL;
    previous = NULL;
}

template <typename T>
List<T>::~List()
{
    makeListEmpty();
}

template <typename T>
bool List<T>::listIsEmpty()
{
    return (head == NULL);
}

template <typename T>
bool List<T>::cursorIsEmpty()
{
    return (cursor == NULL);
}

template <typename T>
void List<T>::toFirst()
{
    cursor = head;
    previous = NULL;
}

template <typename T>
bool List<T>::atFirst()
{
    return (cursor == head);
}

template <typename T>
void List<T>::advance()
{
    previous = cursor;
    cursor = cursor->next;
}

template <typename T>
void List<T>::insertFirst(int key, T data)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    toFirst();
}

template <typename T>
void List<T>::insertAfter(int key, T data)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = cursor->next;
    cursor->next = newNode;
    advance();
}

template <typename T>
void List<T>::insertBefore(int key, T data)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = cursor;
    previous->next = newNode;
    cursor = newNode;
}

template <typename T>
void List<T>::deleteFirst()
{
    if (listIsEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    toFirst();
    deleteNode();
}

template <typename T>
void List<T>::deleteCurrent()
{
    if (listIsEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    if (cursorIsEmpty())
    {
        cout << "Current is empty" << endl;
        return;
    }
    deleteNode();
}

template <typename T>
void List<T>::deleteNode()
{
    if (!cursorIsEmpty())
    {
        Node *temp;
        if (atFirst())
        {
            temp = cursor;
            cursor = cursor->next;
            head = cursor;
            delete temp;
        }
        else
        {
            temp = cursor;
            cursor = cursor->next;
            previous->next = cursor;
            delete temp;
        }
    }
}

template <typename T>
void List<T>::toEnd()
{
    if (listIsEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    if (cursorIsEmpty())
    {
        toFirst();
    }

    while (cursor->next != NULL)
    {
        advance();
    }
}

template <typename T>
void List<T>::deleteEnd()
{
    if (listIsEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    toEnd();
    deleteNode();
}

template <typename T>
void List<T>::makeListEmpty()
{
    toFirst();
    while (cursor != NULL)
    {
        deleteNode();
    }
}

template <typename T>
int List<T>::listSize()
{
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

template <typename T>
bool List<T>::atEnd()
{
    if (listIsEmpty())
        return true;
    else if (cursorIsEmpty())
        return false;
    else
        return (cursor->next == NULL);
}

template <typename T>
void List<T>::updateData(const T &data)
{
    if (!cursorIsEmpty())
    {
        cursor->data = data;
    }
}

template <typename T>
void List<T>::retireveData(T &data, int &key)
{
    if (!cursorIsEmpty())
    {
        data = cursor->data;
        key = cursor->key;
    }
}

template <typename T>
void List<T>::retrieveKey(int &key)
{
    if (!cursorIsEmpty())
    {
        key = cursor->key;
    }
}

template <typename T>
void List<T>::insertEnd(int key, T data)
{
    if (listIsEmpty())
    {
        insertFirst(key, data);
    }
    else
    {
        insertAfter(key, data);
    }
}

template <typename T>
void List<T>::traverse()
{
    while (cursor != NULL)
    {
        cout << cursor->data << endl;
        cursor = cursor->next;
    }
}

template <typename T>
int List<T>::recursive_list_size(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + recursive_list_size(head->next);
}

template <typename T>
int List<T>::recursiveListSize()
{
    toFirst();
    int count = recursive_list_size(head);
    head = cursor;
    return count;
}

template <typename T>
void List<T>::rearrange()
{
    toFirst();
    while (cursor!=NULL)
    {
        Node *inner = cursor->next;
        while (inner != NULL)
        {
            if (inner->key < cursor->key)
            {
                Node temp = *cursor;
                
                cursor->data = inner->data;
                cursor->key = inner->key;

                inner->data = temp.data;
                inner->key = temp.key;
            }
            inner = inner->next;
        }
        advance();
    }
}