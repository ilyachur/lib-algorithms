#include <gtest/gtest.h>
#include <sorting/sorting.h>
#include <gmock/gmock.h>

class heap_sort_tests: public ::testing::Test {
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

TEST_F(heap_sort_tests, sort_array_with_default_compare) {
    int A [6] = {10, -5, 2, 40, -30, 3};

    Sorting::Heap::sort(A, 6);
    ASSERT_THAT(A, testing::ElementsAre(-30, -5, 2, 3, 10, 40));
}

TEST_F(heap_sort_tests, sort_array_with_custom_compare) {
    int A [6] = {10, -5, 2, 40, -30, 3};
    Sorting::Heap::sort(A, 6, std::greater<int>());

    ASSERT_THAT(A, testing::ElementsAre(40, 10, 3, 2, -5, -30));
    Sorting::Heap::sort(A, 6, [](int a, int b) {
        return a < b;
    });

    ASSERT_THAT(A, testing::ElementsAre(-30, -5, 2, 3, 10, 40));
}

TEST_F(heap_sort_tests, sort_array_with_compare_strings) {
    std::string A [6] = {"first", "second", "third", "fourth", "fifth", "sixth"};
    Sorting::Heap::sort(A, 6);
    EXPECT_EQ("first", A[1]);
    EXPECT_EQ("second", A[3]);
    EXPECT_EQ("third", A[5]);
    EXPECT_EQ("fourth", A[2]);
    EXPECT_EQ("fifth", A[0]);
    EXPECT_EQ("sixth", A[4]);
}

TEST_F(heap_sort_tests, sort_big_random_array) {
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

    Sorting::Heap::sort(unsortedArr, 10000);
    for (unsigned int i = 0; i < 10000; i++) {
        EXPECT_EQ(sortedArr[i], unsortedArr[i]);
    }
    EXPECT_EQ(false, arraysNotEquals(sortedArr, unsortedArr, 10000));
}