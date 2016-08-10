#pragma once

#include "../algorithms/algorithms.h"
#include <stdexcept>

namespace Structures {
    template <class T>
    class Queue {
    private:
        T *array = nullptr;
        int head = 0;
        int size = 0;
        int tail = 0;

        void realloc(int delta_size) {
            int new_size = size + delta_size;
            T * new_array = new T[new_size];
            int copy_size = Algorithms::min(new_size, tail - head + 1);
            for (int i = 0, k = head; i < copy_size; i++, k++) {
                new_array[i] = array[k];
            }
            tail = copy_size - 1;
            delete[] array;
            size = new_size;
            head = 0;
            array = new_array;
        }
    public:
        Queue() {}
        Queue(const int& capacity) {
            size = capacity;
            array = new T[size];
        }
        ~Queue() {
            if (array != nullptr) {
                delete [] array;
                size = 0;
            }
        }

        bool isEmpty() noexcept {
            return tail == 0 || array == nullptr || head == tail;
        }

        void push(const T& element) noexcept {
            if (array == nullptr) {
                array = new T[10];
                size = 10;
                tail = 0;
            }
            if (tail == size - 1) {
                realloc(size);
            }
            array[tail] = element;
            tail++;
        }

        T pop() {
            if (isEmpty()) {
                throw std::runtime_error("Queue is empty!!!");
            }
            T element = array[head];
            head++;
            if (tail - head < (size - 1) / 2) {
                realloc(-((int)(size - 1) / 2));
            }
            return element;
        }
    };
}