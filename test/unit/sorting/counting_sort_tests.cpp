#include <gtest/gtest.h>
#include <sorting/sorting.h>
#include <gmock/gmock.h>

class counting_sort_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    template <class T>
    bool arraysNotEquals(T *arr1, T *arr2, unsigned int size) {
        for (auto i = 0; i < size; i++) {
            if (arr1[i] != arr2[i]) {
                return true;
            }
        }
        return false;
    }
};

TEST_F(counting_sort_tests, sort_array_with_counting_sort) {
    int A [6] = {-10, 1, 2, 40, 40, 3};

    Sorting::Counting::sort(A, 6, -10, 50);
    ASSERT_THAT(A, testing::ElementsAre(-10, 1, 2, 3, 40, 40));
}

TEST_F(counting_sort_tests, sort_big_random_array) {
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
    EXPECT_EQ(true, arraysNotEquals(sortedArr, unsortedArr, 10000));

    Sorting::Counting::sort(unsortedArr, 10000, (unsigned int)10000);
    for (unsigned int i = 0; i < 10000; i++) {
        EXPECT_EQ(sortedArr[i], unsortedArr[i]);
    }
    EXPECT_EQ(false, arraysNotEquals(sortedArr, unsortedArr, 10000));
}

TEST_F(counting_sort_tests, sort_big_random_array_with_minus) {
    int sortedArr [10000];
    int unsortedArr [10000];
    for (int i = -5000, k = 0; i < 10000 - 5000; i++, k++) {
        sortedArr[k] = i;
        unsortedArr[k] = i;
    }
    for(uint i = 0; i < 10000; i++) {
        unsigned int changeWith = (unsigned int) (rand() % 10000);
        int tmp = unsortedArr[changeWith];
        unsortedArr[changeWith] = unsortedArr[i];
        unsortedArr[i] = tmp;
    }
    EXPECT_EQ(true, arraysNotEquals(sortedArr, unsortedArr, 10000));

    Sorting::Counting::sort(unsortedArr, 10000, -5000, 10000);
    for (unsigned int i = 0; i < 10000; i++) {
        EXPECT_EQ(sortedArr[i], unsortedArr[i]);
    }
    EXPECT_EQ(false, arraysNotEquals(sortedArr, unsortedArr, 10000));
}