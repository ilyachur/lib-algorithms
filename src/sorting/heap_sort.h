#pragma once

#include "../algorithms/heap.h"

namespace Sorting {
    namespace Heap {

        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) noexcept {
            Algorithms::Heap<T> heap(array, size);
            heap.build([&](T a, T b) {
                if (!comp(a, b)) {
                    return a;
                }
                return b;
            });
            for(int i = size - 1; i >= 1; i--) {
                T tmp = heap.getPtr()[0];
                heap.getPtr()[0] = heap.getPtr()[i];
                heap.getPtr()[i] = tmp;
                heap.heapSize--;
                heap.applyRule(0);
            }
            for (int i = 0; i < size; i++) {
                array[i] = heap.getPtr()[i];
            }
        }

        template <class T>
        void sort(T * array, size_t size) noexcept {
            sort(array, size, std::less<T>());
        }
    }
}