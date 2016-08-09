#pragma once

#include "sorting/sorting.h"

namespace Algorithms {
    namespace Selection {
        template <class T, class Compare>
        T randomized(T * array, int size, int index, Compare comp) noexcept {
            // ~ O(n)
            // bad case O(n^2)
            if (size == 1) {
                return array[0];
            }
            int randIndex = rand() % size;

            T tmp = array[size - 1];
            array[size - 1] = array[randIndex];
            array[randIndex] = tmp;

            int i = 0;
            for (int j = 0; j < size - 1; j++) {
                if (comp(array[j], array[size - 1])) {
                    T tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                    i++;
                }
            }
            tmp = array[size - 1];
            array[size - 1] = array[i];
            array[i] = tmp;

            if (i == index) {
                return array[i];
            } else if (i >= index) {
                return randomized(array, i, index, comp);
            } else {
                return randomized(array + (i + 1), size - (i + 1), index - (i + 1), comp);
            }
        }

        template <class T>
        T randomized(T * array, int size, int index) noexcept {
            return randomized(array, size, index, std::less<T>());
        }

        template <class T, class Compare>
        T select(T * array, int size, int index, Compare comp) noexcept {
            if (size == 1) {
                return array[0];
            }
            // ~ O(n)
            T tmp;
            if (size >= 5) {
                int new_arrays_size = (int) size / 5;
                T *arrays[5];
                int arraysSize[5];
                T medians[5];
                for (int i = 0; i < 5; i++) {
                    arrays[i] = array + i * (new_arrays_size);
                    arraysSize[i] = new_arrays_size;
                    if (i == 4) {
                        arraysSize[i] = size - 4 * (new_arrays_size);
                    }
                    Sorting::Insertion::sort(arrays[i], arraysSize[i], comp);
                    medians[i] = select(arrays[i], arraysSize[i], (int) (new_arrays_size / 2), comp);
                }
                T globalMedian = randomized(medians, 5, 2, comp);
                int randIndex = 0;
                for (int i = 0; i < size; i++) {
                    if (globalMedian == array[i]) {
                        randIndex = i;
                        break;
                    }
                }

                tmp = array[size - 1];
                array[size - 1] = array[randIndex];
                array[randIndex] = tmp;
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
            tmp = array[size - 1];
            array[size - 1] = array[i];
            array[i] = tmp;

            if (i == index) {
                return array[i];
            } else if (i >= index) {
                return select(array, i, index, comp);
            } else {
                return select(array + (i + 1), size - (i + 1), index - (i + 1), comp);
            }
        }

        template <class T>
        T select(T * array, int size, int index) noexcept {
            return select(array, size, index, std::less<T>());
        }
    }
}