#pragma once

#include "find_subarray.h"
#include "select.h"
#include "heap.h"

namespace Algorithms {
    template <class T>
    T min(T *array, int size) {
        T min_el = array[0];
        for (int i = 1; i < size; i++) {
            if (min_el > array[i]) {
                min_el = array[i];
            }
        }
        return min_el;
    }

    template <class T>
    T min(T a, T b) {
        T arr[2];
        arr[0] = a;
        arr[1] = b;
        return min(arr, 2);
    }

    template <class T>
    T max(T *array, int size) {
        T max_el = array[0];
        for (int i = 1; i < size; i++) {
            if (max_el < array[i]) {
                max_el = array[i];
            }
        }
        return max_el;
    }

    template <class T>
    T max(T a, T b) {
        T arr[2];
        arr[0] = a;
        arr[1] = b;
        return max(arr, 2);
    }
}