//
// Created by Sergio on 8/25/2017.
//

#include <stdexcept>
#include "DoublyLinkedList.h"

using namespace jr;

template <typename T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(const T & data) : next(nullptr), previous(nullptr), data(data) { }

template <typename T>
void DoublyLinkedList<T>::insert(const T& data) {
    if (!first) {
        first = new DoublyLinkedListNode<T>(data);
        last = first;
        return;
    }

    DoublyLinkedListNode<T>* wrapper = new DoublyLinkedListNode<T>(data);
    wrapper->next = first;
    first->previous = wrapper;
    first = wrapper;
}

template <typename T>
void DoublyLinkedList<T>::remove(const T& data) {
    DoublyLinkedListNode<T>* current = first;
    while(current) {
        if (current->data == data) {

            if (current->previous) {
                current->previous->next = current->next;
            }
            if (current->next) {
                current->next->previous = current->previous;
            } else { //current is last
                last = current->previous;
            }

            delete current;
            return;
        }
    }
}

template<typename T>
const T& DoublyLinkedList<T>::get(int index) const {
    int currentIndex = 0;
    DoublyLinkedListNode<T>* currentNode = first;

    while (currentNode) {
        if (currentIndex == index) {
            return currentNode->data;
        }
        currentIndex++;
        currentNode = currentNode->next;
    }

    throw std::out_of_range("No such index");
}

template <typename T>
T& DoublyLinkedList<T>::get(int index) {
    return
        const_cast<T&>(
            static_cast<const DoublyLinkedList&>(*this).get(index)
        ); //sharing code with const version of get by
        // casting self as const to call const version of get and then getting rid of the constness
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return first == nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DoublyLinkedListNode<T>* current = first;
    DoublyLinkedListNode<T>* next;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}
