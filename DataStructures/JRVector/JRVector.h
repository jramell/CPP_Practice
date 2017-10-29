#ifndef SERGIOTEST_JRVECTOR_H
#define SERGIOTEST_JRVECTOR_H

namespace jr {

    template<typename T>
    class JRVector {
        int lastIndex;
        int capacity;
        T* elements[];

    public:
        template<typename T>
        JRVector() const;

        template<typename T>
        JRVector<T>(int initialSize) const;

        template<typename T>
        JRVector<T>(int initialSize, const T& initialValue) const;

        template<typename T>
        ~JRVector<T>();

        /**
         * Changes the vector capacity to "newSize". If resized to a capacity that can't fit all
         * of its current elements, removes the last size-capacity elements from the array.
         */
        template<typename T>
        void resize(int newCapacity);

        /**
         * Adds data to the vector. Resizes vector if at full capacity.
         * @param data element to be added to the vector
         */
        template<typename T>
        void push_back(const T& data);

        /**
         * Removes element at index from the vector.
         * @throws std::out_of_range if index is invalid or not in the vector
         */
        template<typename T>
        void erase(int index);

        /**
         * Removes elements in range [startIndex, endIndex) from the vector. If endIndex is higher than
         * the last index in the array, erases everything after startIndex
         * @throws std::out_of_range if startIndex is invalid or not in the vector, and if endIndex < startIndex
         */
        template<typename T>
        void erase(int startIndex, int endIndex);

        /**
         * Removes all elements from the array
         */
        template<typename T>
        void clear();

        /**
         * @return reference to element at the specified index
         * @throws std::out_of_range if the index is invalid or not in the vector
         */
        template<typename T>
        T& at(int index);

        /**
         * @return reference to element at the specified index
         * @throws std::out_of_range if the index is invalid or not in the vector
         */
        template<typename T>
        const T& at(int index) const;

        /**
         * @return amount of elements in the array
         */
        int size();

        /**
         * @return true if the vector is empty (size is 0), false if it's not.
         */
        bool empty();
    };
}

#include "JRVector.cpp"

#endif //SERGIOTEST_JRVECTOR_H
