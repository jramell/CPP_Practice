#include "HashTable.h"

//would using std::hash and using std::size_t and things like that be detrimental for code quality?
//too much documentation?

using jr::HashTable;
using std::size_t;

template<typename K, typename V, typename HashGenerator>
HashTable<K,V,HashGenerator>::HashTable(int initialCapacity = DEFAULT_CAPACITY, float maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR) :
        _capacity(initialCapacity),
        _size(0),
        _loadFactor(0),
        _maxLoadFactor(maxLoadFactor) {
            buckets = new UniqueBucket<K,V>[_capacity];
        };

template<typename K, typename V, typename HashGenerator>
HashTable<K,V,HashGenerator>::~HashTable() {
    delete buckets;
};

template<typename K, typename V, typename HashGenerator>
std::pair<std::pair<K,V>&, bool> HashTable<K,V,HashGenerator>::emplace(K key, V value) {
    size_t targetIndex = HashGenerator()(key) % _capacity;
    std::pair<std::pair<K,V>&, bool> inserted = buckets[targetIndex].insert(std::pair<K,V>(key,value));
    if(inserted.second) {
        _size++;
    }
    return inserted;
};

template<typename K, typename V, typename HashGenerator>
bool HashTable<K,V,HashGenerator>::empty() {
    return _size == 0;
}