#ifndef SERGIOTEST_UNIQUEBUCKET_H
#define SERGIOTEST_UNIQUEBUCKET_H

#include <utility>
#include <forward_list>

template <typename K, typename V>
struct UniqueBucket {
    using iterator = typename std::forward_list<std::pair<K,V>>::iterator;

    int _size;
    std::forward_list<std::pair<K,V>> elements;

    UniqueBucket();
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
    std::pair<std::pair<K,V>&, bool> insert(const std::pair<K,V>& keyValuePair);

    /**
     * If there's an element with key key in the bucket, erases it and returns true. Otherwise, returns false.
     * @param key key of the element to be erased.
     * @return true if there was an element with key key in the HashTable and it was erased, false if there wasn't such an element.
     */
    bool erase(const K& key);

    iterator begin();
    iterator end();
};

#include "UniqueBucket.cpp"

#endif //SERGIOTEST_UNIQUEBUCKET_H
