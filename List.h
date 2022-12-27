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
        int key;
        T data;
        Node *next;
    };
    Node *head, *cursor, *previous;
    int recursive_list_size(Node *);

public:
    List();
    ~List();
    bool listIsEmpty();
    bool cursorIsEmpty();
    void toFirst();
    bool atFirst();
    void advance();
    void insertFirst(int, T);
    void insertAfter(int, T);
    void insertBefore(int, T);
    void deleteFirst();
    void deleteCurrent();
    void deleteNode();
    void toEnd();
    void deleteEnd();
    void makeListEmpty();
    int listSize();
    bool atEnd();
    void updateData(const T &);
    void retireveData(T &, int &);
    void retrieveKey(int &);
    void insertEnd(int, T);
    void traverse();
    int recursiveListSize();
    void rearrange();
};

#include "List.cpp"
#endif