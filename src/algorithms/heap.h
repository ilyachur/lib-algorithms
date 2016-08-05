#pragma once

#include <stdexcept>
#include <functional>
#include <cmath>

namespace Algorithms {
    template<class T>
    class Heap {
    private:
        T* array = nullptr;
        int heapHeight = 0;
        std::function<const T& (const T& a, const T& b)> operation = [](const T& a, const T& b) {
            return a;
        };

        void swap(int indexLeft, int indexRight) {
            if (indexLeft >= heapSize || indexRight >= heapSize) return;
            T tmp = array[indexLeft];
            array[indexLeft] = array[indexRight];
            array[indexRight] = tmp;
        }

        void destroy() {
            heapSize = 0;
            heapHeight = 0;
            if (array != nullptr) {
                delete []array;
                array = nullptr;
            }
        }

    public:
        // TODO: Fix it
        int heapSize = 0;

        Heap() {}
        Heap(T *arr, int size) {
            heapSize = size;
            heapHeight = (int)log2(heapSize) + 1;
            array = new T[size];
            for (int i = 0; i < size; i++) {
                array[i] = arr[i];
            }
        }
        Heap(int size) {
            heapSize = size;
            heapHeight = (int)log2(heapSize) + 1;
            array = new T[size];
        }
        ~Heap() {
            destroy();
        }

        inline int height() const noexcept {
            return heapHeight;
        }

        T* getPtr() const noexcept {
            return array;
        }

        T getParent(const int& index) {
            int parentIndex = getParentIndex(index);
            if (parentIndex < 0)  throw std::runtime_error("Incorrect index!");
            return array[parentIndex];
        }

        int getParentIndex(const int& index) const noexcept {
            if (index >= heapSize) return -1;
            return (int)((index - 1) / 2);
        }

        T getLeft(const int& index) {
            int leftIndex = getLeftIndex(index);
            if (leftIndex < 0) throw std::runtime_error("Incorrect index!");
            return array[leftIndex];
        }

        int getLeftIndex(const int& index) const noexcept {
            if (index >= heapSize || index*2 + 1 >= heapSize) return -1;
            return index*2 + 1;
        }

        T getRight(const int& index) {
            int rightIndex = getRightIndex(index);
            if (rightIndex < 0) throw std::runtime_error("Incorrect index!");
            return array[rightIndex];
        }

        int getRightIndex(const int& index) const noexcept {
            if (index >= heapSize || index*2 + 2 >= heapSize) return -1;
            return index*2 + 2;
        }

        void build() {
            for (int i = heapSize / 2; i >= 0; i--) {
                applyRule(i);
            }
        }

        void build(T *arr, int size) {
            destroy();
            heapSize = size;
            heapHeight = (int)log2(heapSize) + 1;
            array = new T[size];
            for (int i = 0; i < size; i++) {
                array[i] = arr[i];
            }
            build();
        }

        void build(std::function<const T& (const T& a, const T& b)> operat) {
            operation = operat;
            build();
        }

        void build(T *arr, int size, std::function<const T& (const T& a, const T& b)> operat) {
            operation = operat;
            build(arr, size);
        }

        void applyRule(const int& index) {
            int l = getLeftIndex(index);
            int r = getRightIndex(index);
            int largest = index;
            if (l > 0 && array[l]  == operation(array[index], array[l])) {
                largest = l;
            }
            if (r > 0 && array[r]  == operation(array[largest], array[r])) {
                largest = r;
            }
            if (largest != index) {
                swap(index, largest);
                applyRule(largest);
            }
        }
    };
}