#pragma once
#include <vector>
#include "insertion_sort.h"

namespace Sorting {
    namespace Bucket {
        inline void sort(unsigned int * array, size_t size, unsigned int min_number, unsigned int max_number) noexcept {
            std::vector<unsigned int>* tempArray = new std::vector<unsigned int>[size];
            for (auto i = 0; i < size; i++) {
                tempArray[((unsigned int)((array[i] - min_number) * size)) / (max_number - min_number)].push_back(array[i]);
            }
            for (auto i = 0; i < size; i++) {
                Sorting::Insertion::sort(tempArray[i].data(), tempArray[i].size());
            }
            for (auto i = 0, j = 0; i < size || j < size; j++) {
                for (auto k = 0; k < tempArray[j].size(); k++) {
                    array[i] = tempArray[j].data()[k];
                    i++;
                }
            }
            delete[] tempArray;
        }
    }
}