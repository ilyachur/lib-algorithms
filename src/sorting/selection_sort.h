#pragma once

#include <functional>

namespace Sorting {
    namespace Selection {
        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) {
            for (int i = 0; i < size - 1; i++) {
                int min = i;
                for (int j = i + 1; j < size; j++) {
                    if (comp(array[j], array[min])) {
                        min = j;
                    }
                }
                T obj = array[i];
                array[i] = array[min];
                array[min] = obj;
            }
        }

        template <class T>
        void sort(T * array, size_t size) {
            sort(array, size, std::less<T>());
        }
    }
}