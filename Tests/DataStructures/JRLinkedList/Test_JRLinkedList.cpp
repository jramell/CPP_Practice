#include "gtest/gtest.h"
#include "../../../DataStructures/JRLinkedList/JRLinkedList.h"

int first = 10;
int second = 13;
int last = 43;

JRLinkedList<int> setupScenario1() {
    JRLinkedList<int> mockList;
    mockList = JRLinkedList<int>();
    mockList.insert(last);
    for (int i = 0; i < 5; i++) {
        mockList.insert(i);
    }
    mockList.insert(second);
    mockList.insert(first);
}

TEST(Test_JRLinkedList, Constructor) {
    ASSERT_NO_THROW(JRLinkedList<short> emptyList);
}

TEST(Test_JRLinkedList, EmptyTest)
{
    JRLinkedList<short> emptyList;
    ASSERT_EQ(true, emptyList.empty());
}

TEST(Test_JRLinkedList, InsertOne)
{
    JRLinkedList<short> list;
    ASSERT_NO_THROW(list.insert(100));
    ASSERT_EQ(100, list.get(0));
    ASSERT_EQ(false, list.empty());
}

TEST(Test_JRLinkedList, Front)
{
    JRLinkedList<short> list;
    ASSERT_NO_THROW(list.insert(100));
    ASSERT_EQ(100, list.front());
}

TEST(Test_JRLinkedList, InsertSeveral)
{
    JRLinkedList<short> list;
    for(int i = 0; i < 5; i++) {
        ASSERT_NO_THROW(list.insert(i));
    }
    ASSERT_EQ(4, list.front());
}

TEST(Test_JRLinkedList, InsertStrings)
{
    JRLinkedList<std::string> list;
    list.insert("HAIL2U");
    list.insert("KATSU");
    ASSERT_EQ("KATSU", list.front());
}

TEST(Test_JRLinkedList, PushBackOne)
{
    JRLinkedList<std::string> list;
    ASSERT_NO_THROW(list.push_back("a"));
    ASSERT_NO_THROW(list.front());
    ASSERT_EQ("a", list.front());
}

TEST(Test_JRLinkedList, Back)
{
    JRLinkedList<std::string> list;
    list.push_back("HAIL2U");
    ASSERT_EQ("HAIL2U", list.back());
}

TEST(Test_JRLinkedList, PushBackSeveral) //when I push_back two times, the test doesn't run. I don't understand why yet.
{
    JRLinkedList<int> list;
    for(int i = 0; i < 5; i++) {
        ASSERT_NO_THROW(list.push_back(i));
    }
    ASSERT_EQ(4, list.back());
    ASSERT_EQ(0, list.front());
}

TEST(Test_JRLinkedList, GetRandom)
{
    JRLinkedList<int> list;
    for(int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    ASSERT_EQ(2, list.get(2));
}

TEST(Test_JRLinkedList, GetLast)
{
    JRLinkedList<int> list;
    for(int i = 0; i < 100; i++) {
        list.push_back(i);
    }
    ASSERT_EQ(99, list.get(99));
}

TEST(Test_JRLinkedList, RemoveUniqueValue)
{
    JRLinkedList<int> list;
    for(int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    list.remove(2);
    ASSERT_EQ(3, list.get(2));
    ASSERT_EQ(0, list.front());
}

TEST(Test_JRLinkedList, RemoveDuplicateValue)
{
    JRLinkedList<int> list;
    for(int i = 0; i < 5; i++) {
        list.push_back(10);
    }
    list.remove(10);
    ASSERT_EQ(true, list.empty());
    ASSERT_THROW(list.front(), std::out_of_range);
}

TEST(Test_JRLinkedList, RangeIteration)
{
    JRLinkedList<int> list;
    for(int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    int counter = 0;
    for(int number : list) {
        ASSERT_EQ(counter, number);
        counter++;
    }
}


//write tests that combine several methods to make sure the LinkedList correctly maintains first and last
//on every case