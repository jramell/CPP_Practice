#ifndef SERGIOTEST_HASHTABLE_H
#define SERGIOTEST_HASHTABLE_H

#include <cstdint>
#include <forward_list>
#include "UniqueBucket/UniqueBucket.h"

namespace jr {
    template<typename K, typename V, typename HashGenerator = std::hash<K>>
    class HashTable {
        UniqueBucket<K,V>* buckets;
        /**
         * Size of the underlying container
         */
        std::size_t _capacity;

        /**
         * Amount of elements in the HashTable
         */
        std::size_t _size;

        /**
         * Current load factor
         */
        float _loadFactor;

        /**
         * Maximum load the factor the HashTable can reach.
         */
        float _maxLoadFactor;

        /**
         * Checks if HashTable's container can be resized to newCapacity without going over the maximum load factor.
         * If it can, sets underlying container capacity to newCapacity and resinserts all key value pairs in the new container.
         * In this case, be aware that if newCapacity is less than the previous capacity, the number of collisions might increase.
         * If resizing container to newCapacity would result in size/capacity > maxLoadFactor, the HashTable won't be rehashed.
         * @param newCapacity
         */
        void rehash(std::size_t newCapacity);

    public:
        /**
         * Initializes Hash Table with default capacity
         */
        HashTable();

        /**
         * Initializes Hash Table with capacity initialCapacity
         * @param initialCapacity
         */
        HashTable(std::size_t initialCapacity);

        ~HashTable();

        /**
         * @param key key of the element to be retrieved
         * @return if there's an element with that key in the HashTable, a reference to it. Throws exception otherwise.
         * @throws std::out_of_range if there is not an element with key key in the HashTable.
         */
        V& at(K key);

        /**
         * @return current capacity of the HashTable's underlying container
         */
        std::size_t capacity();

        /**
         * Constructs a key-value pair with the key and values passed as parameters and inserts it into the HashTable.
         * @param key key of the key-value pair
         * @param value value of the key-value pair
         * @return if another pair with that key already exists, returns a pair whose first value will be that pair, and whose second
         *          value will be false. Otherwise, returns iterator to pair whose first value is the newly inserted
         *          key-value pair, and whose second parameter would be true.
         */
        std::pair<const std::pair<K,V>&, bool> emplace(K key, V value);

        /**
         * If there's an element with key key in the HashTable, erases it and returns true. Otherwise, returns false.
         * @param key key of the element to be erased.
         * @return true if there was an element with key key in the HashTable and it was erased, false if there wasn't such an element.
         */
        bool erase(const K& key);

        /**
         * @return current load factor of the HashTable. LoadFactor = numberOfElements/containerCapacity
         */
        float loadFactor();

        /**
         * @return current max load factor of the HashTable. Everytime load factor surpasses it, HashTable will
         * rehash itself.
         */
        float maxLoadFactor();

        /**
         * Sets the HashTable's maximum load factor to maxLoadFactor.
         * @param newLoadFactor new maximum load factor for the HashTable.
         */
        void setMaxLoadFactor(float maxLoadFactor);

        /**
         * @return true if the HashTable contains no elements, false otherwise.
         */
        bool empty();

        /**
         * All the elements in the unordered_map container are dropped: their destructors are called, and they are
         * removed from the container, leaving it with a size of 0.
         */
        void clear();
    };
}

#include "HashTable.cpp"

#endif //SERGIOTEST_HASHTABLE_H
