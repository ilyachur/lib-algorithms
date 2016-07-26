#include <gtest/gtest.h>
#include <algorithms/algorithms.h>
#include <gmock/gmock.h>
#include <functional>

class find_subarray_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:

};

TEST_F(find_subarray_tests, find_all_elements) {
    int A [1] = {10};
    size_t out_size = 0;
    int *Aptr = Algorithms::Find::subArray(A, 1, out_size);
    EXPECT_EQ(1, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(A[i], Aptr[i]);
    }

    int B [3] = {10, -5, 20};
    int *Bptr = Algorithms::Find::subArray(B, 3, out_size);
    EXPECT_EQ(3, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(B[i], Bptr[i]);
    }
}

TEST_F(find_subarray_tests, sort_array_with_default_compare) {
    int C [7] = {-20, 10, -5, 2, 40, -30, 3};
    size_t out_size = 0;
    int *Cptr = Algorithms::Find::subArray(C, 7, out_size);
    EXPECT_EQ(4, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(C[i + 1], Cptr[i]);
    }
}

TEST_F(find_subarray_tests, sort_array_with_custom_parameters) {
    int C [7] = {-20, 120, -50, 2, -40, 30, 3};
    size_t out_size = 0;
    int *Cptr = Algorithms::Find::subArray(C, 7, out_size, [](int a, int b) {
        return a+b;
    }, std::less<int>());
    EXPECT_EQ(3, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(C[i + 2], Cptr[i]);
    }

    Cptr = Algorithms::Find::subArray(C, 7, out_size, [](int a, int b) {
        return a+b;
    }, std::greater<int>());
    EXPECT_EQ(1, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(C[i + 1], Cptr[i]);
    }

    Cptr = Algorithms::Find::subArray(C, 7, out_size, [](int a, int b) {
        return a*b;
    }, std::greater<int>());
    EXPECT_EQ(4, out_size);
    for (int i = 0; i < out_size; i++) {
        EXPECT_EQ(C[i], Cptr[i]);
    }
}