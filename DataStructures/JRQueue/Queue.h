//
// Created by Sergio on 8/20/2017.
//

#ifndef SERGIOTEST_QUEUE_H
#define SERGIOTEST_QUEUE_H

struct QueueNode {
    QueueNode* next;
    int data;
    QueueNode(int);
};

class Queue {
private:
    QueueNode* top;
    QueueNode* tail;
public:
    void push(int);
    int& front();
    void pop();
    bool isEmpty();
    Queue();
    ~Queue();
    Queue(const Queue&);
};


#endif //SERGIOTEST_QUEUE_H
