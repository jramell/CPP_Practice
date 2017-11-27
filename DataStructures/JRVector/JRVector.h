#ifndef SERGIOTEST_JRVECTOR_H
#define SERGIOTEST_JRVECTOR_H

namespace jr {

    template<typename T>
    class JRVector {
        unsigned int _size;
        unsigned int _capacity;
        T* elements;

    public:
        using iterator = T*;

        JRVector<T>();

        JRVector<T>(unsigned int initialSize);

        JRVector<T>(unsigned int initialSize, const T& initialValue);

        ~JRVector<T>();

        /**
         * Changes the vector capacity to "newSize". If resized to a capacity that can't fit all
         * of its current elements, removes the last size-capacity elements from the array.
         */
        void resize(unsigned int newCapacity);

        /**
         * Adds data to the vector. Resizes vector if at full capacity.
         * @param data element to be added to the vector
         */
        void push_back(const T& data);

        /**
         * Removes element at index from the vector.
         * @throws std::out_of_range if index is invalid or not in the vector
         */
        void erase(unsigned int index);

        /**
         * Removes elements in range [startIndex, endIndex) from the vector. If endIndex is higher than
         * the last index in the array, erases everything after startIndex
         * @throws std::out_of_range if startIndex is invalid or not in the vector, and if endIndex < startIndex
         */
        void erase(unsigned int startIndex, unsigned int endIndex);

        /**
         * Removes all elements from the array
         */
        void clear();

        /**
         * @return reference to element at the specified index
         * @throws std::out_of_range if the index is invalid or not in the vector
         */
        T& at(unsigned int index);

        /**
         * @return reference to element at the specified index
         * @throws std::out_of_range if the index is invalid or not in the vector
         */
        const T& at(unsigned int index) const;

        /**
         * @return amount of elements in the array
         */
        int size();

        /**
         * @return true if the vector is empty (size is 0), false if it's not.
         */
        bool empty();

        /**
         * @return size of allocated storage capacity
         */
        int capacity();

        iterator begin();

        iterator end();
    };
}

#include "JRVector.cpp"

#endif //SERGIOTEST_JRVECTOR_H
