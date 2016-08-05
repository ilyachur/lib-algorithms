#include <gtest/gtest.h>
#include <algorithms/algorithms.h>
#include <gmock/gmock.h>

class heap_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:

};

TEST_F(heap_tests, get_parent) {
    int heapArr[8] = {10, -5, 20, -40, 60, 2, -3, 5};

    Algorithms::Heap <int> heap(heapArr, 8);

    EXPECT_EQ(10, heap.getParent(0));
    EXPECT_EQ(10, heap.getParent(1));
    EXPECT_EQ(10, heap.getParent(2));
    EXPECT_EQ(-5, heap.getParent(3));
    EXPECT_EQ(-5, heap.getParent(4));
    EXPECT_EQ(20, heap.getParent(5));
    EXPECT_EQ(20, heap.getParent(6));
    EXPECT_EQ(-40, heap.getParent(7));
    EXPECT_THROW(heap.getParent(107), std::runtime_error);

    EXPECT_EQ(0, heap.getParentIndex(0));
    EXPECT_EQ(0, heap.getParentIndex(1));
    EXPECT_EQ(0, heap.getParentIndex(2));
    EXPECT_EQ(1, heap.getParentIndex(3));
    EXPECT_EQ(1, heap.getParentIndex(4));
    EXPECT_EQ(2, heap.getParentIndex(5));
    EXPECT_EQ(2, heap.getParentIndex(6));
    EXPECT_EQ(3, heap.getParentIndex(7));
    EXPECT_EQ(-1, heap.getParentIndex(107));
}

TEST_F(heap_tests, get_heap_height) {
    Algorithms::Heap <int> heap0(1);
    EXPECT_EQ(1, heap0.height());
    Algorithms::Heap <int> heap1(2);
    EXPECT_EQ(2, heap1.height());
    Algorithms::Heap <int> heap2(3);
    EXPECT_EQ(2, heap2.height());
    Algorithms::Heap <int> heap3(4);
    EXPECT_EQ(3, heap3.height());
    Algorithms::Heap <int> heap4(5);
    EXPECT_EQ(3, heap4.height());
    Algorithms::Heap <int> heap5(6);
    EXPECT_EQ(3, heap5.height());
    Algorithms::Heap <int> heap6(7);
    EXPECT_EQ(3, heap6.height());
    Algorithms::Heap <int> heap7(8);
    EXPECT_EQ(4, heap7.height());
}

TEST_F(heap_tests, get_left) {
    int heapArr[8] = {10, -5, 20, -40, 60, 2, -3, 5};

    Algorithms::Heap <int> heap(heapArr, 8);

    EXPECT_EQ(-5, heap.getLeft(0));
    EXPECT_EQ(-40, heap.getLeft(1));
    EXPECT_EQ(2, heap.getLeft(2));
    EXPECT_EQ(5, heap.getLeft(3));
    EXPECT_THROW(heap.getLeft(4), std::runtime_error);
    EXPECT_THROW(heap.getLeft(107), std::runtime_error);

    EXPECT_EQ(1, heap.getLeftIndex(0));
    EXPECT_EQ(3, heap.getLeftIndex(1));
    EXPECT_EQ(5, heap.getLeftIndex(2));
    EXPECT_EQ(7, heap.getLeftIndex(3));
    EXPECT_EQ(-1, heap.getLeftIndex(4));
}

TEST_F(heap_tests, get_right) {
    int heapArr[8] = {10, -5, 20, -40, 60, 2, -3, 5};

    Algorithms::Heap <int> heap(heapArr, 8);

    EXPECT_EQ(20, heap.getRight(0));
    EXPECT_EQ(60, heap.getRight(1));
    EXPECT_EQ(-3, heap.getRight(2));
    EXPECT_THROW(heap.getRight(3), std::runtime_error);
    EXPECT_THROW(heap.getRight(4), std::runtime_error);
    EXPECT_THROW(heap.getRight(107), std::runtime_error);

    EXPECT_EQ(2, heap.getRightIndex(0));
    EXPECT_EQ(4, heap.getRightIndex(1));
    EXPECT_EQ(6, heap.getRightIndex(2));
    EXPECT_EQ(-1, heap.getRightIndex(3));
    EXPECT_EQ(-1, heap.getRightIndex(4));
}

TEST_F(heap_tests, build_heap) {
    int heapArr[8] = {10, -5, 20, -40, 60, 2, -3, 5};

    Algorithms::Heap <int> heap(heapArr, 8);

    heap.build();

    int * array = heap.getPtr();

    for(int i = 0; i < 8; i++) {
        EXPECT_EQ(heapArr[i], array[i]);
    }
    heap.build([](int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    });
    array = heap.getPtr();

    EXPECT_EQ(60, array[0]);
    EXPECT_EQ(10, array[1]);
    EXPECT_EQ(20, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(-5, array[4]);
    EXPECT_EQ(2, array[5]);
    EXPECT_EQ(-3, array[6]);
    EXPECT_EQ(-40, array[7]);

    heap.build([](int a, int b) {
        return std::min(a, b);
    });

    array = heap.getPtr();
    EXPECT_EQ(-40, array[0]);
    EXPECT_EQ(-5, array[1]);
    EXPECT_EQ(-3, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(60, array[4]);
    EXPECT_EQ(2, array[5]);
    EXPECT_EQ(20, array[6]);
    EXPECT_EQ(10, array[7]);

    heap.build([](int a, int b) {
        return std::max(a, b);
    });

    array = heap.getPtr();
    EXPECT_EQ(60, array[0]);
    EXPECT_EQ(10, array[1]);
    EXPECT_EQ(20, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(-5, array[4]);
    EXPECT_EQ(2, array[5]);
    EXPECT_EQ(-3, array[6]);
    EXPECT_EQ(-40, array[7]);


    int heapArr2[4] = {10, -2, 30, 50};
    heap.build(heapArr2, 4, [](int a, int b) {
        return std::min(a, b);
    });

    array = heap.getPtr();
    EXPECT_EQ(-2, array[0]);
    EXPECT_EQ(10, array[1]);
    EXPECT_EQ(30, array[2]);
    EXPECT_EQ(50, array[3]);
}