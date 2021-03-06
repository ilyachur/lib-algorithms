#pragma once

#include <functional>

namespace Sorting {
    namespace Insertion {
        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) noexcept {
            for (int i = 1; i < size; i++) {
                int j = i - 1;
                T key = array[i];
                while (j >= 0 && comp(key, array[j])) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
            }
        }

        template <class T>
        void sort(T * array, size_t size) noexcept {
            sort(array, size, std::less<T>());
        }
    }
}