#include <gtest/gtest.h>
#include <algorithms/algorithms.h>
#include <gmock/gmock.h>

class select_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
};

TEST_F(select_tests, select_element) {
    unsigned int A [6] = {10, 1, 2, 40, 40, 3};

    unsigned int test = Algorithms::Selection::select(A, 6, 2);
    EXPECT_EQ(3, test);
    test = Algorithms::Selection::select(A, 6, 3);
    EXPECT_EQ(10, test);
    test = Algorithms::Selection::select(A, 6, 5);
    EXPECT_EQ(40, test);
    test = Algorithms::Selection::select(A, 6, 0);
    EXPECT_EQ(1, test);
}

TEST_F(select_tests, sort_big_random_array) {
    unsigned int sortedArr [10000];
    unsigned int unsortedArr [10000];
    for (unsigned int i = 0; i < 10000; i++) {
        sortedArr[i] = i;
        unsortedArr[i] = i;
    }
    for(unsigned int i = 0; i < 10000; i++) {
        unsigned int changeWith = (unsigned int) (rand() % 10000);
        unsigned int tmp = unsortedArr[changeWith];
        unsortedArr[changeWith] = unsortedArr[i];
        unsortedArr[i] = tmp;
    }

    unsigned int test = Algorithms::Selection::select(unsortedArr, 10000, 100);
    EXPECT_EQ(100, test);

    test = Algorithms::Selection::select(unsortedArr, 10000, 5600);
    EXPECT_EQ(5600, test);
}

TEST_F(select_tests, select_from_big_random_signed_array) {
    int unsortedArr [10000];
    for (int i = -5000, k = 0; i < 10000 - 5000; i++, k++) {
        unsortedArr[k] = i;
    }
    for(uint i = 0; i < 10000; i++) {
        unsigned int changeWith = (unsigned int) (rand() % 10000);
        int tmp = unsortedArr[changeWith];
        unsortedArr[changeWith] = unsortedArr[i];
        unsortedArr[i] = tmp;
    }

    int test = Algorithms::Selection::select(unsortedArr, 10000, 100);
    EXPECT_EQ(100 - 5000, test);

    test = Algorithms::Selection::select(unsortedArr, 10000, 5600);
    EXPECT_EQ(5600 - 5000, test);
}