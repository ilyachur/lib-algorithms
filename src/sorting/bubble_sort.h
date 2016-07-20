#pragma once

#include <functional>
#include <iostream>

namespace Sorting {
    namespace Bubble {

        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) noexcept {
            for (int i = 0; i < size - 1; i++) {
                for (int j = size - 1; j > i; j--) {
                    if (comp(array[j], array[j - 1])) {
                        T tmp = array[j];
                        array[j] = array[j - 1];
                        array[j - 1] = tmp;
                    }
                }
            }
        }

        template <class T>
        void sort(T * array, size_t size) noexcept {
            sort(array, size, std::less<T>());
        }
    }
}