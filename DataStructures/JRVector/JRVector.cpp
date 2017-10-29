#include <stdexcept>
#include "JRVector.h"

using jr::JRVector;

template <typename T>
JRVector<T>::JRVector() {
    lastIndex = -1;
    capacity = 25;
    elements = new T[capacity];
}

template <typename T>
JRVector<T>::JRVector(int initialSize) {
    lastIndex = -1;
    capacity = initialSize;
    elements = new T[capacity];
}

template <typename T>
JRVector<T>::JRVector(int initialSize, const T& initialValue) {
    lastIndex = initialSize-1;
    capacity = initialSize;
    elements = new T[capacity];
    for (int i = 0; i < initialSize; i++) {
        elements[i] = initialValue;
    }
}

template <typename T>
void JRVector<T>::resize(int newCapacity) {
    if (newCapacity < lastIndex) {
        lastIndex = newCapacity-1;
    }
    T* newElements = new T[newCapacity];
    int elementLimit = (newCapacity < capacity)? newCapacity : capacity;
    for (int i = 0; i < elementLimit; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

template <typename T>
void JRVector<T>::clear() {
    this->~JRVector();
    this->JRVector();
}

template <typename T>
JRVector<T>::~JRVector() {
    delete[] elements;
}

template <typename T>
void JRVector<T>::push_back(const T& data) {
    if (capacity == 0) {
        JRVector();
    } else if (capacity == lastIndex+1) {
        resize(capacity*2);
    }
    elements[++lastIndex] = data;
}

template <typename T>
void JRVector<T>::erase(int index) {
    erase(index, index+1);
}

template <typename T>
void JRVector<T>::erase(int startIndex, int endIndex) {
    if (startIndex < 0 || startIndex > lastIndex || endIndex < startIndex) {
        throw std::out_of_range("Invalid startIndex");
    }
    capacity = size()-(endIndex-startIndex);
    T* newArray = new T[capacity];
    //copy all elements [0, startIndex) into newArray
    for (int i = 0; i < startIndex; i++) {
        newArray[i] = elements[i];
    }
    //copy all elements [endIndex, lastIndex] into newArray
    for (int i = endIndex; i <= lastIndex; i++) {
        newArray[i-(endIndex-startIndex)] = elements[i];
    }
    lastIndex = capacity-1;
    delete[] elements;
    elements = newArray;
}

template <typename T>
int JRVector<T>::size() {
    return lastIndex+1;
}

template <typename T>
T& JRVector<T>::at(int index) {
    return const_cast<T&>(
            static_cast<const JRVector<T>&>(*this).at(index)
    );
}

template <typename T>
const T& JRVector<T>::at(int index) const {
    if (index < 0 || index > lastIndex) {
        throw std::out_of_range("Invalid index");
    }
    return elements[index];
}

template <typename T>
bool JRVector<T>::empty() {
    return size() > 0;
}