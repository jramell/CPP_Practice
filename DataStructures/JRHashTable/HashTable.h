#ifndef SERGIOTEST_HASHTABLE_H
#define SERGIOTEST_HASHTABLE_H

#include <cstdint>
#include <forward_list>

namespace jr {
    /**
     * Hash template akin to std::hash. To define the hash function for a custom-built type, you can either specialize its
     * hash function and add it to the jr namespace or pass that type as a parameter when creating the HashTable.
     */
    template<typename K>
    struct Hash {
        /**
         * @param key key you need the hash for
         * @return hash for the key. It should have low collision probability.
         */
        std::size_t operator()(const K& key) const;

        Hash();
    };

    template<typename K, typename V, typename HashGenerator = Hash<K>>
    class HashTable {
        struct HashTableBucket {
            std::forward_list<std::pair<K,V>> elements;
            /**
             * @return true if the bucket is empty, false otherwise.
             */
            bool empty();

            /**
             * Searches the bucket for an element with key key and returns a reference to it if found. If not found,
             * throws std::out_of_range.
             * @param key key of the element to be retrieved.
             * @return reference to element inside the bucket with key key
             * @throws std::out_of_range if no element with key key is found in the bucket.
             */
            V& at(const K& key);

            /**
             * Checks if there already a pair with the key in keyValuePair. If there is, returns a pair whose first value is
             * an iterator to that pair, and whose second value is false. If there isn't, returns a pair whose first value is an
             * iterator to the newly inserted keyValuePair and whose second value is true.
             * @param keyValuePair
             * @return
             */
            std::pair<const std::pair<K,V>&, bool> insert(std::pair<K,V> keyValuePair);
        };
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

        std::pair<K,V>* elements;

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
         * @return if another pair the key key already exists, returns iterator to pair whose first value will be the existing this existing
         *          pair and whose second value will be false. Otherwise, returns iterator to pair whose first value is the newly inserted
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
