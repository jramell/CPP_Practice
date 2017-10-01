//
// Created by Sergio on 7/20/2017.
//

#ifndef SERGIOTEST_JRLINKEDLISTNODE_H
#define SERGIOTEST_JRLINKEDLISTNODE_H

#include <string>

template <typename T>
class JRLinkedListNode {

    T data;

public:
    JRLinkedListNode<T>* next;

    JRLinkedListNode<T>(T data);
    const T& getData() const;
    T& getData();
};

#include "JRLinkedListNode.cpp"


#endif //SERGIOTEST_JRLINKEDLISTNODE_H
