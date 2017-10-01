//
// Created by Sergio on 8/19/2017.
//

#ifndef SERGIOTEST_STACK_H
#define SERGIOTEST_STACK_H

#include "StackNode.h"


class Stack {
private:
    StackNode* top;
    StackNode* tail;
    void push_back(int data);

public:
    void pop();
    void push(int data);
    int& front();
    bool isEmpty();
    Stack();
    Stack(const Stack&);
    ~Stack();
};


#endif //SERGIOTEST_STACK_H
