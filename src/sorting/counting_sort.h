#pragma once

#include <cmath>

namespace Sorting {
    namespace Counting {

        template <class T>
        void sort(T * array, size_t size, T min_number, T max_number) noexcept {
            max_number++;
            unsigned int * countPlusArray = new unsigned int[max_number];
            unsigned int * countMinusArray = nullptr;
            if (min_number < 0)
                countMinusArray = new unsigned int[abs(min_number) + 1];
            T * returnArray = new T[size];
            for (int i = 0; i < max_number; i++) {
                countPlusArray[i] = 0;
            }
            if (countMinusArray != nullptr) {
                for (int i = 0; i < abs(min_number) + 1; i++) {
                    countMinusArray[i] = 0;
                }
            }
            for (auto i = 0; i < size; i++) {
                if (array[i] < 0 && countMinusArray != nullptr) {
                    countMinusArray[abs(array[i])]++;
                } else {
                    countPlusArray[array[i]]++;
                }
            }
            if (countMinusArray != nullptr) {
                for (int i = abs(min_number); i > 0; i--) {
                    countMinusArray[i - 1] += countMinusArray[i];
                }
                countPlusArray[0] += countMinusArray[0];
            }

            for (int i = 1; i < max_number; i++) {
                countPlusArray[i] += countPlusArray[i - 1];
            }

            for(int i = size - 1; i >= 0; i--) {
                if (array[i] < 0 && countMinusArray != nullptr) {
                    returnArray[countMinusArray[abs(array[i])] - 1] = array[i];
                    countMinusArray[abs(array[i])]--;
                } else {
                    returnArray[countPlusArray[array[i]] - 1] = array[i];
                    countPlusArray[array[i]]--;
                }
            }

            for (auto i = 0; i < size; i++) {
                array[i] = returnArray[i];
            }

            delete[] returnArray;
            delete[] countPlusArray;
            if (countMinusArray != nullptr) {
                delete[] countMinusArray;
            }
        }

        template <class T>
        void sort(T * array, size_t size, T max_number) noexcept {
            sort(array, size, (T)0, max_number);
        }

    }
}