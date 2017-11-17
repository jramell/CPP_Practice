#ifndef SERGIOTEST_HASHTABLE_H
#define SERGIOTEST_HASHTABLE_H

#include <cstdint>
namespace jr {
    template<typename Key, typename Value>
    class HashTable {
        /**
         * Size of the underlying container
         */
        std::size_t _capacity;

        /**
         * Amount of elements in the HashTable
         */
        std::size_t _size;

        /**
         *
         */
        std::size_t _loadFactor;

    public:
        HashTable();
    };
}


#endif //SERGIOTEST_HASHTABLE_H
