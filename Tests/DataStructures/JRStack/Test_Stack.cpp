#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../../DataStructures/JRStack/Stack.h"

using testing::Eq;

namespace {
    class Test_Stack : public testing::Test {
    public:
        Stack stack;
        Test_Stack()
        { }
    };
}

TEST_F(Test_Stack, PushTest)
{
    int top = 52;
    stack.push(top);
    ASSERT_EQ(stack.front(), top);
}

TEST_F(Test_Stack, PopWithOneElementTest)
{
    int top = 52;
    stack.push(top);
    stack.pop();
    ASSERT_THROW(stack.front(), std::out_of_range);
}

TEST_F(Test_Stack, PushTwoElementsTest)
{
    int top = 12;
    int second = 42;
    stack.push(second);
    stack.push(top);
    ASSERT_EQ(stack.front(), top);
}

TEST_F(Test_Stack, PopWithTwoElementsTest)
{
    int top = 12;
    int second = 42;
    stack.push(second);
    stack.push(top);
    stack.pop();
    ASSERT_EQ(stack.front(), second);
}

TEST_F(Test_Stack, PopWhenEmpty)
{
    ASSERT_NO_THROW(stack.pop());
}

TEST_F(Test_Stack, PopOrderTest)
{
    int third = 11;
    int second = 10;
    int first = 9;
    stack.push(third);
    stack.push(second);
    stack.push(first);
    ASSERT_EQ(stack.front(), first);
    stack.pop();
    ASSERT_EQ(stack.front(), second);
    stack.pop();
    ASSERT_EQ(stack.front(), third);
}

TEST_F(Test_Stack, FrontWhenEmpty)
{
    ASSERT_THROW(stack.front(), std::out_of_range);
}

TEST_F(Test_Stack, IsEmptyWhenEmptyTest)
{
    ASSERT_EQ(stack.isEmpty(), true);
}

TEST_F(Test_Stack, IsEmptyWhenNotEmptyTest)
{
    stack.push(10);
    stack.push(stack.front());
    ASSERT_EQ(stack.isEmpty(), false);
}

TEST_F(Test_Stack, CopyConstructorNotEmptyTest)
{
    stack.push(11);
    stack.push(12);
    Stack copy = stack;
    ASSERT_EQ(stack.isEmpty(), false);
}

TEST_F(Test_Stack, CopyConstructorSameElementsTest)
{
    int second = 11;
    int first = 10;
    stack.push(second);
    stack.push(first);
    Stack copy = stack;
    ASSERT_EQ(copy.front(), first);
    copy.pop();
    ASSERT_EQ(copy.front(), second);
    copy.pop();
    ASSERT_EQ(copy.isEmpty(), true);
}

TEST_F(Test_Stack, CopyConstructorIndependentElementsTest)
{
    int second = 11;
    int first = 10;
    stack.push(second);
    stack.push(first);
    Stack copy = stack;
    ASSERT_EQ(copy.front(), first);
    stack.pop();
    ASSERT_EQ(copy.front(), first);
    copy.pop();
    ASSERT_EQ(copy.front(), second);
    copy.pop();
    ASSERT_EQ(stack.front(), second);
    ASSERT_THROW(copy.front(), std::out_of_range);
}