#pragma once

#include "../algorithms/algorithms.h"
#include <stdexcept>

namespace Structures {
    template <class T>
    class Stack {
    private:
        T *array = nullptr;
        int size = 0;
        int top = 0;

        void realloc(int delta_size) {
            int new_size = size + delta_size;
            T * new_array = new T[new_size];
            int copy_size = Algorithms::min(new_size, size);
            for (int i = 0; i < copy_size; i++) {
                new_array[i] = array[i];
            }
            delete[] array;
            size = new_size;
            array = new_array;
        }
    public:
        Stack() {}
        Stack(const int& capacity) {
            size = capacity;
            array = new T[size];
        }
        ~Stack() {
            if (array != nullptr) {
                delete [] array;
                size = 0;
                top = 0;
            }
        }

        bool isEmpty() noexcept {
            return top == 0 || array == nullptr;
        }

        void push(const T& element) noexcept {
            if (array == nullptr) {
                array = new T[10];
                size = 10;
                top = 0;
            }
            if (top == size - 1) {
                realloc(size);
            }
            array[top] = element;
            top++;
        }

        T pop() {
            if (isEmpty()) {
                throw std::runtime_error("Stack is empty!!!");
            }

            top--;
            T element = array[top];
            if (top < (size - 1) / 2) {
                realloc(-((int)(size - 1) / 2));
            }
            return element;
        }
    };
}