#pragma once

#include <functional>
#include <algorithm>

namespace Sorting {
    namespace Quick {

        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) noexcept {
            if (size < 2) {
                return;
            }
            int i = 0;
            for (int j = 0; j < size - 1; j++) {
                if (comp(array[j], array[size - 1])) {
                    T tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                    i++;
                }
            }
            T tmp = array[size - 1];
            array[size - 1] = array[i];
            array[i] = tmp;
            sort(array, i, comp);
            if (size > i + 1) {
                sort(array + i + 1, size - (i + 1), comp);
            }
        }

        template <class T>
        void sort(T * array, size_t size) noexcept {
            sort(array, size, std::less<T>());
        }
    }
}