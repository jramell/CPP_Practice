#include <stdexcept>
#include "JRVector.h"

using jr::JRVector;

template <typename T>
JRVector<T>::JRVector() {
    _size = 0;
    _capacity = 25;
    elements = new T[_capacity];
}

template <typename T>
JRVector<T>::JRVector(unsigned int initialSize) {
    _size = 0; //should be initialSize
    _capacity = initialSize;
    elements = new T[_capacity]; //each element should be acopy of provided element, if it was
    //also, remember the "shouldn't have default constructor" thing
}

template <typename T>
JRVector<T>::JRVector(unsigned int initialSize, const T& initialValue) {
    _size = initialSize;
    _capacity = initialSize;
    elements = new T[_capacity];
    for (unsigned int i = 0; i < initialSize; i++) {
        elements[i] = initialValue;
    }
}

template <typename T>
void JRVector<T>::resize(unsigned int newCapacity) {
    if (newCapacity < _size) {
        _size = newCapacity;
    }
    T* newElements = new T[newCapacity];
    int elementLimit = (newCapacity < _capacity)? newCapacity : _capacity;
    for (unsigned int i = 0; i < elementLimit; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    _capacity = newCapacity;
}

template <typename T>
JRVector<T>::~JRVector() {
    delete[] elements;
}

template <typename T>
void JRVector<T>::clear() {
    resize(0);
    resize(25);
}

template <typename T>
void JRVector<T>::push_back(const T& data) {
    if (_capacity == 0) {
        JRVector();
    } else if (_capacity == _size) {
        resize(_capacity*2);
    }
    elements[_size++] = data;
}

template <typename T>
void JRVector<T>::erase(unsigned int index) {
    erase(index, index+1);
}

template <typename T>
void JRVector<T>::erase(unsigned int startIndex, unsigned int endIndex) {
    if (startIndex >= _size) {
        throw std::out_of_range("startIndex is invalid");
    }
    if(endIndex < startIndex) {
        throw std::out_of_range("startIndex can't be bigger than endIndex");
    }
    int elementsRemoved = (endIndex < _size)? endIndex - startIndex : _size - startIndex;
    _capacity = _size-elementsRemoved;
    T* newArray = new T[_capacity];
    //copy all elements [0, startIndex) into newArray
    for (unsigned int i = 0; i < startIndex; i++) {
        newArray[i] = elements[i];
    }
    //copy all elements [endIndex, lastIndex] into newArray
    for (unsigned int i = endIndex; i < _size; i++) {
        newArray[i-(endIndex-startIndex)] = elements[i];
    }
    _size = _capacity;
    delete[] elements;
    elements = newArray;
}

template <typename T>
int JRVector<T>::size() {
    return _size;
}

template <typename T>
T& JRVector<T>::at(unsigned int index) {
    return const_cast<T&>(
            static_cast<const JRVector<T>&>(*this).at(index)
    );
}

template <typename T>
const T& JRVector<T>::at(unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Invalid index");
    }
    return elements[index];
}

template <typename T>
bool JRVector<T>::empty() {
    return size() == 0;
}

template <typename T>
int JRVector<T>::capacity() {
    return _capacity;
}


template <typename T>
T* JRVector<T>::begin() {
    return &elements[0];
}

template <typename T>
T* JRVector<T>::end() {
    return &elements[_size];
}