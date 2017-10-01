//
// Created by Sergio on 8/20/2017.
//

#include <stdexcept>
#include "Queue.h"

QueueNode::QueueNode(int data) : data(data), next(nullptr) { }

void Queue::push(int data) {
    if (!top) {
        top = new QueueNode(data);
        tail = top;
    } else {
        QueueNode* wrapper = new QueueNode(data);
        tail->next = wrapper;
        tail = wrapper;
    }
}

int& Queue::front() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return top->data;
}

void Queue::pop() {
    if (isEmpty()) {
        return;
    }
    QueueNode* temp = top;
    top = top->next;
    if (!top) { //avoid tail being a dangling pointer when popping the last element
        tail = nullptr;
    }
    delete temp;
}

bool Queue::isEmpty() {
    return top == nullptr;
}

Queue::Queue() : top(nullptr), tail(nullptr) { }

Queue::~Queue() {
    while (top) {
        pop();
    }
}

Queue::Queue(const Queue& original) : Queue() {
    QueueNode* current = original.top;
    while (current) {
        push(current->data);
        current = current->next;
    }
}