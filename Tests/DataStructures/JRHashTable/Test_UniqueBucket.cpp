#include <string>
#include "../../../DataStructures/JRHashTable/UniqueBucket/UniqueBucket.h"

#include "gtest/gtest.h"

TEST(Test_JRVector, Empty) {
    UniqueBucket<int, int> bucket;
    EXPECT_EQ(true, bucket.empty());
}

TEST(Test_JRVector, InsertEmpty) {
    UniqueBucket<int, int> bucket;
    std::pair<int, int> p(1, 10);
    bucket.insert(p);
    ASSERT_NO_THROW(bucket.insert(p));
    ASSERT_EQ(false, bucket.empty());
}

TEST(Test_JRVector, InsertSeveralUnique) {
    UniqueBucket<int, int> bucket;
    for(int i = 0; i < 10; i++) {
        std::pair<int, int> p(i, i);
        std::pair<std::pair<int, int>, bool> result;
        ASSERT_NO_THROW(result = bucket.insert(p));
        ASSERT_EQ(i, result.first.first);
        ASSERT_EQ(i, result.first.second);
        ASSERT_EQ(true, result.second);
    }
    ASSERT_EQ(false, bucket.empty());
}

TEST(Test_JRVector, InsertSeveralDuplicate) {
    UniqueBucket<int, int> bucket;
    bucket.insert(std::pair<int, int>(1, 50));
    for(int i = 0; i < 10; i++) {
        std::pair<int, int> p(1, i);
        std::pair<std::pair<int, int>, bool> result;
        ASSERT_NO_THROW(result = bucket.insert(p));
        EXPECT_EQ(1, result.first.first);
        EXPECT_EQ(50, result.first.second);
        EXPECT_EQ(false, result.second);
    }
    EXPECT_EQ(false, bucket.empty());
}

TEST(Test_JRVector, At_NonExistantEmpty) {
    UniqueBucket<int, int> bucket;
    ASSERT_THROW(bucket.at(10), std::out_of_range);
}

TEST(Test_JRVector, At_NonExistantAfterInserting) {
    UniqueBucket<int, int> bucket;
    for(int i = 0; i < 2; i++) {
        bucket.insert(std::pair<int, int>(i, i));
    }
    ASSERT_THROW(bucket.at(10), std::out_of_range);
}

TEST(Test_JRVector, At_Existant) {
    UniqueBucket<int, int> bucket;
    std::pair<int, int> justInserted(55, 100);
    auto result = bucket.insert(justInserted);
    std::pair<int, int>& insertedPair = result.first;
   ASSERT_EQ(insertedPair.second, bucket.at(55));
}

TEST(Test_JRVector, At_SeveralExistantUnique) {
    UniqueBucket<int, int> bucket;
    for(int i = 0; i < 10; i++) {
        std::pair<int, int> justInserted(i, i);
        auto result = bucket.insert(justInserted);
        std::pair<int, int>& insertedPair = result.first;
        EXPECT_EQ(i, insertedPair.second);
        ASSERT_EQ(insertedPair.second, bucket.at(i));
    }
}

TEST(Test_JRVector, At_SeveralExistantDuplicate) {
    using std::string;
    UniqueBucket<int, string> bucket;
    bucket.insert(std::pair<int, string>(1, "test"));
    for(int i = 0; i < 10; i++) {
        std::pair<int, string> duplicateKey(1, std::to_string(i));
        auto result = bucket.insert(duplicateKey);
        std::pair<int, string>& originalPair = result.first;
        EXPECT_EQ("test", originalPair.second);
        ASSERT_EQ(originalPair.second, bucket.at(1));
    }
}