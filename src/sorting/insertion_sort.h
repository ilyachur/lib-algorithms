#pragma once

#include <functional>

namespace Sorting {
    namespace Insetrion {
        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) {
            bool res = comp(array[1], array[0]);
            for (int i = 1; i < size; i++) {
                int j = i - 1;
                T key = array[i];
                while (j >= 0 && comp(array[j], key)) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
            }
        }

        template <class T>
        void sort(T * array, size_t size) {
            sort(array, size, std::greater<T>());
        }
    }
}