#pragma once

namespace Algorithms {
    namespace Selection {
        template <class T, class Compare>
        T randomized(T * array, int size, int index, Compare comp) noexcept {
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
    }
}