#ifndef List_H
#define List_H
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head, *cursor, *previous;

public:
    List();
    ~List();
    bool listIsEmpty();
    bool cursorIsEmpty();
    void toFirst();
    bool atFirst();
    void advance();
    void insertFirst(T);
    void insertAfter(T);
    void insertBefore(T);
    void deleteFirst();
    void deleteCurrent();
    void deleteNode();
    void toEnd();
    void deleteEnd();
    void makeListEmpty();
    int listSize();
    bool atEnd();
    void updateData(const T &);
    void retireveData(T &);
    void insertEnd(T);
};

#include "List.cpp"
#endif