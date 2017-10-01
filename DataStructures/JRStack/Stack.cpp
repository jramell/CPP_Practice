//
// Created by Sergio on 8/19/2017.
//

#include <stdexcept>
#include "Stack.h"
#include <iostream>

void Stack::pop() {
    if (!top) {
        return;
    }
    StackNode* temp = top;
    if (tail == top) {
        tail = nullptr; //if that was our last element
    }
    top = top->next;
    delete temp;
}

void Stack::push(int data) {
    if (!top) {
        top = new StackNode(data);
        tail = top;
    } else {
        StackNode* wrapper = new StackNode(data);
        wrapper->next = top;
        top = wrapper;
    }
}

int& Stack::front() {
    if (!top) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push_back(int data) {
    if (!top) {
        push(data);
        return;
    }
    StackNode* wrapper = new StackNode(data);
    tail->next = wrapper;
    tail = wrapper;
}

Stack::Stack() : top(nullptr) { }

Stack::Stack(const Stack& originalStack) : top(nullptr) {
    StackNode* current = originalStack.top;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}

Stack::~Stack() {
    while (top) {
        pop();
    }
}