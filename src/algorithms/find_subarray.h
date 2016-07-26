#pragma once

#include <functional>

namespace Algorithms {
    namespace Find {
        template <class T, class Operation, class Compare>
        T * subArray(T * array, size_t size, size_t& output_size, Operation operation, Compare comp) noexcept {
            if (size == 1) {
                output_size = 1;
                return array;
            }
            size_t middle = size / 2;
            size_t left_size = 0;
            T* left_array = subArray(array, middle, left_size, operation, comp);
            T leftOperationResult(left_array[0]);
            for (int i = 1; i < left_size; i++) {
                leftOperationResult = operation(leftOperationResult, left_array[i]);
            }

            size_t right_size = 0;
            T* right_array = subArray(array + middle, size - middle, right_size, operation, comp);
            T rightOperationResult(right_array[0]);
            for (int i = 1; i < left_size; i++) {
                rightOperationResult = operation(rightOperationResult, right_array[i]);
            }

            T crossLeftOperationResult(array[middle - 1]);
            T crossLeftOperationResultTmp(array[middle - 1]);
            int resultLeftIndex = middle - 1;
            for (int i = middle - 2; i >= 0; i--) {
                crossLeftOperationResultTmp = operation(crossLeftOperationResultTmp, array[i]);
                if (comp(crossLeftOperationResultTmp, crossLeftOperationResult)) {
                    crossLeftOperationResult = crossLeftOperationResultTmp;
                    resultLeftIndex = i;
                }
            }

            T crossRightOperationResult(array[middle]);
            T crossRightOperationResultTmp(array[middle]);
            int resultRightIndex = middle;
            for (auto i = middle + 1; i < size; i++) {
                crossRightOperationResultTmp = operation(crossRightOperationResultTmp, array[i]);
                if (comp(crossRightOperationResultTmp, crossRightOperationResult)) {
                    crossRightOperationResult = crossRightOperationResultTmp;
                    resultRightIndex = i;
                }
            }
            T *cross_array = array + resultLeftIndex;
            size_t cross_size = resultRightIndex + 1 - resultLeftIndex;
            T crossOperationResult = operation(crossLeftOperationResult, crossRightOperationResult);

            if (comp(leftOperationResult, crossOperationResult) && comp(leftOperationResult, rightOperationResult)) {
                output_size = left_size;
                return left_array;
            } else if (comp(rightOperationResult, crossOperationResult) && comp(rightOperationResult, leftOperationResult)) {
                output_size = right_size;
                return right_array;
            }
            output_size = cross_size;
            return cross_array;
        };

        template <class T, class Operation>
        T * subArray(T * array, size_t size, int& output_size, Operation operation) noexcept {
            return subArray(array, size, output_size, operation, std::greater<T>());
        };

        template <class T>
        T * subArray(T * array, size_t size, size_t& output_size) noexcept {
            return subArray(array, size, output_size, [](T a, T b) {
                return a + b;
            }, std::greater<T>());
        };
    }
}