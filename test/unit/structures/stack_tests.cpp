#include <gtest/gtest.h>
#include <structures/structures.h>
#include <gmock/gmock.h>

class stack_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
};

TEST_F(stack_tests, push_and_pop_elements) {
    Structures::Stack<int> stack;
    EXPECT_EQ(true, stack.isEmpty());
    EXPECT_THROW(stack.pop(), std::runtime_error);
    for (int i = 0; i < 20; i++) {
        stack.push(i);
    }

    for (int i = 19; i >= 0; i--) {
        EXPECT_EQ(i, stack.pop());
    }
}
