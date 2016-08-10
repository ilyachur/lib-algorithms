#include <gtest/gtest.h>
#include <structures/structures.h>
#include <gmock/gmock.h>

class queue_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
};

TEST_F(queue_tests, push_and_pop_elements) {
    Structures::Queue<int> stack;
    EXPECT_EQ(true, stack.isEmpty());
    EXPECT_THROW(stack.pop(), std::runtime_error);
    for (int i = 0; i < 20; i++) {
        stack.push(i);
    }

    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(i, stack.pop());
    }
}
