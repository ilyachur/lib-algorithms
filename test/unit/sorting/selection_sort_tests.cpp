#include <gtest/gtest.h>
#include <sorting/sorting.h>
#include <gmock/gmock.h>

class selection_sort_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:

};

TEST_F(selection_sort_tests, sort_array_with_default_compare) {
    int A [6] = {10, -5, 2, 40, -30, 3};

    Sorting::Selection::sort(A, 6);
    ASSERT_THAT(A, testing::ElementsAre(-30, -5, 2, 3, 10, 40));
}

TEST_F(selection_sort_tests, sort_array_with_custom_compare) {
    int A [6] = {10, -5, 2, 40, -30, 3};
    Sorting::Selection::sort(A, 6, std::greater<int>());

    ASSERT_THAT(A, testing::ElementsAre(40, 10, 3, 2, -5, -30));
    Sorting::Selection::sort(A, 6, [](int a, int b) {
        return a < b;
    });

    ASSERT_THAT(A, testing::ElementsAre(-30, -5, 2, 3, 10, 40));
}

TEST_F(selection_sort_tests, sort_array_with_compare_strings) {
    std::string A [6] = {"first", "second", "third", "fourth", "fifth", "sixth"};
    Sorting::Selection::sort(A, 6);
    EXPECT_EQ("first", A[1]);
    EXPECT_EQ("second", A[3]);
    EXPECT_EQ("third", A[5]);
    EXPECT_EQ("fourth", A[2]);
    EXPECT_EQ("fifth", A[0]);
    EXPECT_EQ("sixth", A[4]);
}