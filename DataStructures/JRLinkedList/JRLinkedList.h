//
// Created by Sergio on 7/20/2017.
//

#ifndef SERGIOTEST_JRLINKEDLIST_H
#define SERGIOTEST_JRLINKEDLIST_H

#include "JRLinkedListNode.h"
#include <stdexcept>

/*
 * Singly linked list. Does not manage the deallocation of T
 */
template <typename T>
class JRLinkedList {

    JRLinkedListNode<T>* head;
    JRLinkedListNode<T>* tail;

public:
    /* Creates new linked list with data 0 as head */
    JRLinkedList();

    ~JRLinkedList();

    /* Creates new linked list with specified node as head */
    JRLinkedList(JRLinkedListNode<T> head);

    /* Inserts at end */
    void push_back(const T& object);

    /* Inserts at start */
    void insert(const T& object);
    void remove(int position);
    const T& get(int position) const;
    T& get(int position);

    const T& getLastElement() const;
};

#include "JRLinkedList.cpp"

#endif //SERGIOTEST_JRLINKEDLIST_H
