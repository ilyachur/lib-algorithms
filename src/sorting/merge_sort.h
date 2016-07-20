#pragma once

#include <functional>
#include <iostream>

namespace Sorting {
    namespace Merge {

        template <class T, class Compare>
        void sort(T * array, size_t size, Compare comp) noexcept {
            if (size < 2)
                return;

            int left_size = size / 2;
            int right_size = size - left_size;
            sort(array, left_size, comp);
            sort(array + left_size, right_size, comp);

            int left_index = 0;
            int right_index = 0;

            T *left_arr = new T[left_size];
            for (int i = 0; i < left_size; i++) {
                left_arr[i] = array[i];
            }
            T *right_arr = new T[right_size];
            for (int i = left_size, k = 0; i < size; i++, k++) {
                right_arr[k] = array[i];
            }

            for(int i = 0; i < size; i++) {
                if (left_index < left_size && right_index < right_size) {
                    if (comp(left_arr[left_index], right_arr[right_index])) {
                        array[i] = left_arr[left_index++];
                    } else {
                        array[i] = right_arr[right_index++];
                    }
                } else if (left_index < left_size) {
                    array[i] = left_arr[left_index++];
                } else if (right_index < right_size) {
                    array[i] = right_arr[right_index++];
                }
            }

            delete []left_arr;
            delete []right_arr;
        }

        template <class T>
        void sort(T * array, size_t size) noexcept {
            sort(array, size, std::less<T>());
        }
    }
}