#include <gtest/gtest.h>
#include <sorting/sorting.h>
#include <gmock/gmock.h>

class radix_sort_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    bool arraysNotEquals(unsigned int *arr1, unsigned int *arr2, unsigned int size) {
        for (auto i = 0; i < size; i++) {
            if (arr1[i] != arr2[i]) {
                return true;
            }
        }
        return false;
    }
};

TEST_F(radix_sort_tests, sort_array_with_bucket_sort) {
    unsigned int A [6] = {10, 1, 2, 40, 40, 3};

    Sorting::Radix::sort(A, 6);
    ASSERT_THAT(A, testing::ElementsAre(1, 2, 3, 10, 40, 40));
}

TEST_F(radix_sort_tests, sort_big_random_array) {
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

    Sorting::Radix::sort(unsortedArr, 10000);
    for (unsigned int i = 0; i < 10000; i++) {
        EXPECT_EQ(sortedArr[i], unsortedArr[i]);
    }
    EXPECT_EQ(false, arraysNotEquals(sortedArr, unsortedArr, 10000));
}