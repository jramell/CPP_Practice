#include <stdexcept>
#include "UniqueBucket.h"
template<typename K, typename V>
UniqueBucket<K,V>::UniqueBucket() : _size(0) { }

template<typename K, typename V>
bool UniqueBucket<K,V>::empty() {
    return _size == 0;
}

template<typename K, typename V>
V& UniqueBucket<K,V>::at(const K& key) {
    for(std::pair<K,V>& pair : elements) {
        if(pair.first == key) {
            return pair.second;
        }
    }
    throw std::out_of_range("Element not found");
}

template<typename K, typename V>
std::pair<std::pair<K,V>&, bool> UniqueBucket<K,V>::insert(const std::pair<K,V>& keyValuePair) {
    for(auto& pair : elements) {
        if(pair.first == keyValuePair.first) {
            return std::pair<std::pair<K,V>&, bool>(pair, false);
        }
    }
    elements.push_front(keyValuePair);
    _size++;
    return std::pair<std::pair<K,V>&, bool>(elements.front(), true);
};

template<typename K, typename V>
bool UniqueBucket<K,V>::erase(const K& key) {
    for(auto& pair : elements) {
        if(pair.first == key) {
            elements.remove(pair);
            return true;
        }
    }
    return false;
};

template<typename K, typename V>
typename UniqueBucket<K,V>::iterator UniqueBucket<K,V>::begin() {
    return elements.begin();
};

template<typename K, typename V>
typename UniqueBucket<K,V>::iterator UniqueBucket<K,V>::end() {
    return elements.end();
};