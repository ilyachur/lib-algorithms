#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <math/math.h>
#include <stdexcept>

class matrix_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:

};

TEST_F(matrix_tests, crete_matrix) {
    Math::Matrix::Mat<int> mat1;
    EXPECT_EQ(0, mat1.rows());
    EXPECT_EQ(0, mat1.cols());
    EXPECT_EQ(nullptr, mat1.get_data());

    int arr[9] = {2, 3, 5, -1, 4, -2, 5, 6, 7};
    Math::Matrix::Mat<int> mat2(arr, 3, 3);
    EXPECT_EQ(3, mat2.rows());
    EXPECT_EQ(3, mat2.cols());
    EXPECT_NE(nullptr, mat2.get_data());
    EXPECT_NE(arr, mat2.get_data());
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(arr[i], mat2.get_data()[i]);
    }

    std::vector<int> vec = {2, 3, 5, -1, 4, -2, 5, 6, 7};
    Math::Matrix::Mat<int> mat3(vec, 3, 3);
    EXPECT_EQ(3, mat3.rows());
    EXPECT_EQ(3, mat3.cols());
    EXPECT_NE(nullptr, mat3.get_data());
    EXPECT_NE(arr, mat3.get_data());
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(arr[i], mat3.get_data()[i]);
    }


    EXPECT_THROW(Math::Matrix::Mat<int> mat4(vec, -3, 3), std::runtime_error);
    EXPECT_THROW(Math::Matrix::Mat<int> mat5(vec, 20, 3), std::runtime_error);
    EXPECT_THROW(Math::Matrix::Mat<int> mat6(arr, 3, -3), std::runtime_error);
    EXPECT_THROW(Math::Matrix::Mat<int> mat7(-3, -3), std::runtime_error);
}

TEST_F(matrix_tests, matrix_elements) {
    int arr[9] = {2, 3, 5, -1, 4, -2, 5, 6, 7};
    Math::Matrix::Mat<int> mat2(arr, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(arr[i*3 + j], mat2.at(j, i));
        }
    }
    mat2.set(0, 2, 1);
    EXPECT_EQ(0, mat2.at(2, 1));

    EXPECT_THROW(mat2.at(5, 2), std::runtime_error);
    EXPECT_THROW(mat2.at(1, -2), std::runtime_error);
    EXPECT_THROW(mat2.set(0, 5, 2), std::runtime_error);
    EXPECT_THROW(mat2.set(0, 1, -2), std::runtime_error);
}

TEST_F(matrix_tests, square_multiple_o3_test) {
    int arr[9] = {1, 0, 0, 0, 2, 0, 0, 0, 3};
    Math::Matrix::Mat<int> mat2(arr, 3, 3);

    Math::Matrix::Mat<int> matResult = Math::Matrix::square_multiple_o3(mat2, mat2);
    EXPECT_EQ(3, matResult.rows());
    EXPECT_EQ(3, matResult.cols());

    int check_arr[9] = {1, 0, 0, 0, 4, 0, 0, 0, 9};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(check_arr[i*3 + j], matResult.at(j, i));
        }
    }

    Math::Matrix::Mat<int> mat3(4, 3);
    matResult = Math::Matrix::square_multiple_o3(mat2, mat3);
    EXPECT_EQ(0, matResult.rows());
    EXPECT_EQ(0, matResult.cols());
    EXPECT_EQ(nullptr, matResult.get_data());
}