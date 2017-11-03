#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../../DataStructures/JRLinkedList/JRLinkedList.h"

using testing::Eq;

namespace {
    class Test_JRLinkedList : public testing::Test {
    public:
        JRLinkedList<int> mockList;
        int first = 10;
        int second = 13;
        int last = 43;
        Test_JRLinkedList()
        {
            SetupScenario1();
        }
        void SetupScenario1()
        {
            mockList = JRLinkedList<int>();
            mockList.insert(last);
            for (int i = 0; i < 5; i++)
            {
                mockList.insert(i);
            }
            mockList.insert(second);
            mockList.insert(first); //list inserts in the beginning
        }
    };
}

TEST_F(Test_JRLinkedList, FirstElementTest)
{
    ASSERT_EQ(mockList.get(0), first);
}
TEST_F(Test_JRLinkedList, LastElementTest)
{
    ASSERT_EQ(mockList.getLastElement(), last);
}

TEST_F(Test_JRLinkedList, RemoveFirstElement)
{
    mockList.remove(0);
    ASSERT_EQ(mockList.get(0), second);
}

/*
TEST_F(Test_JRLinkedList, name5)
{
    ASSERT_EQ(mockList.get(0), second);
}*/
