#pragma once

namespace Sorting {
    namespace Counting {
        inline void sort(unsigned int * array, size_t size, unsigned int max_number) noexcept {
            max_number++;
            unsigned int * countArray = new unsigned int[max_number];
            unsigned int * returnArray = new unsigned int[size];
            for (int i = 0; i < max_number; i++) {
                countArray[i] = 0;
            }
            for (auto i = 0; i < size; i++) {
                countArray[array[i]]++;
            }

            for (int i = 1; i < max_number; i++) {
                countArray[i] += countArray[i - 1];
            }

            for(int i = size - 1; i >= 0; i--) {
                returnArray[countArray[array[i]] - 1] = array[i];
                countArray[array[i]]--;
            }

            for (auto i = 0; i < size; i++) {
                array[i] = returnArray[i];
            }
        }
    }
}