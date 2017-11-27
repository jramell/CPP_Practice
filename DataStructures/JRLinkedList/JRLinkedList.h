#ifndef SERGIOTEST_JRLINKEDLIST_H
#define SERGIOTEST_JRLINKEDLIST_H

#include <stdexcept>

//more documentation?
namespace jr {
    template <typename T>
    class JRLinkedList {
        struct JRLinkedListNode {
            T data;
            JRLinkedListNode* next;

            JRLinkedListNode(T data);
        };

        JRLinkedListNode* head;
        JRLinkedListNode* tail;
    public:
        class iterator {
            iterator& operator++();
        };
        JRLinkedList();
        ~JRLinkedList();

        bool empty() const;
        bool empty();

        void push_back(const T& object);

        /* Inserts at beginning */
        void insert(const T& object);

        /**
         * Removes all elements with value
         * @throws std::out_of_range if list is empty
         */
        void remove(const T& value);

        /**
         * @return reference to the first element of the list
         * @throws std::out_of_range if the list is empty
         */
        const T& front() const;
        T& front();

        const T& get(int position) const;
        T& get(int position);

        const T& back() const;
        T& back();
    };
}

#include "JRLinkedList.cpp"

#endif //SERGIOTEST_JRLINKEDLIST_H
