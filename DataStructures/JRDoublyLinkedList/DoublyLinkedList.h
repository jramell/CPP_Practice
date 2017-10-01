#ifndef SERGIOTEST_DOUBLYLINKEDLIST_H
#define SERGIOTEST_DOUBLYLINKEDLIST_H

namespace jr {
    template <typename T>
    struct DoublyLinkedListNode {
        DoublyLinkedListNode* next;
        DoublyLinkedListNode* previous;
        T data;
        DoublyLinkedListNode(const T&);
    };

    template <typename T>
    class DoublyLinkedList {

    public:
        void insert(const T&);
        void remove(const T&);
        T& get(int index);
        const T& get(int index) const;
        bool isEmpty() const;
        ~DoublyLinkedList();

        DoublyLinkedListNode<T>* first;
        DoublyLinkedListNode<T>* last;
    };
}

#include "DoublyLinkedList.cpp"


#endif //SERGIOTEST_DOUBLYLINKEDLIST_H
