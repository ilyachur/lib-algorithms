#pragma once
#include <vector>
#include "insertion_sort.h"

namespace Sorting {
    namespace Radix {
        template <class T>
        void sort(T *array, size_t size) {
            // Max byte number in type
            int k = sizeof(T);
            // Cycle by all bytes
            for(int i = 0; i < k; i++) {
                // 256 values are maximum for byte
                int c[256] = {0};

                // Calculating number of elements in array for each byte as in counting sort
                for(int j = 0; j < size; j++)
                {
                    c[(array[j] >> (8 * i) & 255)]++;
                }

                for(int j = 1; j < 256;j++)
                {
                    c[j] += c[j-1];
                }

                T* tmpArr = new T[size];
                for(int j = size - 1; j > -1;j--)
                {
                    tmpArr[--c[(array[j] >> (8 * i) & 255)]] = array[j];
                }
                for(int j = 0; j < size; j++)
                {
                    array[j] = tmpArr[j];
                }
                delete[] tmpArr;
            }
        }
    }
}