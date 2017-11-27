#include "HashTable.h"

//would using std::hash and using std::size_t and things like that be detrimental for code quality?
//too much documentation?

using jr::HashTable;

template<typename K, typename V, typename HashGenerator> //will this still allow me to instantiate a HashTable<K,V> trusting the default
                                                        //template parameter?
HashTable<K,V, HashGenerator>::HashTableBucket::HashTableBucket() {
    int k = 0;
}
/*
template<typename K, typename V>
HashTable<K,V>::HashTable() :
        _size(0),
        _capacity(25),
        _loadFactor(0.0f),
        _maxLoadFactor(1.0f) { } //just a test
*/
