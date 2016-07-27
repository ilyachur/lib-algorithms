#pragma once
#include <vector>
#include <stdexcept>

namespace Math {
    namespace Matrix {
        template <class T>
        class Mat {
        private:
            T* matrix;
            int mRows;
            int mCols;

            void destroy() {
                if (matrix) {
                    delete[] matrix;
                }
                matrix = nullptr;
                mRows = 0;
                mCols = 0;
            }
        public:
            Mat(): mRows(0), mCols(0), matrix(nullptr) {}
            Mat(const T* mat,  const int& r, const int& c): mRows(r), mCols(c) {
                if (mRows < 0 || mCols < 0) throw std::runtime_error("Incorrect matrix sizes!");
                matrix = new T[mCols*mRows];
                for(auto i = 0; i < mRows*mCols; i++) {
                    matrix[i] = mat[i];
                }
            }

            Mat(const Mat& rhs) {
                mRows = rhs.rows();
                mCols = rhs.cols();
                if (mRows * mCols > 0) {
                    matrix = new T[mCols * mRows];
                    for (auto i = 0; i < mRows * mCols; i++) {
                        matrix[i] = rhs.get_data()[i];
                    }
                } else {
                    matrix = nullptr;
                }
            }

            Mat(Mat && rhs) {
                mRows = rhs.rows();
                mCols = rhs.cols();
                if (mRows * mCols > 0) {
                    matrix = new T[mCols * mRows];
                    for (auto i = 0; i < mRows * mCols; i++) {
                        matrix[i] = rhs.get_data()[i];
                    }
                } else {
                    matrix = nullptr;
                }
                rhs.destroy();
            }

            Mat(const int& r, const int& c): mRows(r), mCols(c) {
                if (mRows < 0 || mCols < 0) throw std::runtime_error("Incorrect matrix sizes!");
                matrix = new T[mCols*mRows];
            }

            Mat(const std::vector<T>& mat,  const int& r, const int& c): mRows(r), mCols(c) {
                if (mRows < 0 || mCols < 0) throw std::runtime_error("Incorrect matrix sizes!");
                if (mat.size() != mCols*mRows) throw std::runtime_error("Incorrect size of matrix data!");
                matrix = new T[mCols*mRows];
                for(auto i = 0; i < mCols*mRows; i++) {
                    matrix[i] = mat.at(i);
                }
            }
            ~Mat() {
                destroy();
            }

            T at(const int& c, const int& r) const  {
                if (c < 0 || r < 0 || c >= mCols || r >= mRows) throw std::runtime_error("Incorrect indexes of matrix data!");
                if (!matrix) throw "Matrix is null!";
                return matrix[r*mCols + c];
            }

            void set(T newValue, const int& c, const int& r)  {
                if (c < 0 || r < 0 || c >= mCols || r >= mRows) throw std::runtime_error("Incorrect indexes of matrix data!");
                if (!matrix) throw "Matrix is null!";
                matrix[r*mCols + c] = newValue;
            }

            int rows() const {
                return mRows;
            }

            int cols() const {
                return mCols;
            }

            T* get_data() const {
                return matrix;
            }

            Mat& operator=(const Mat& mat) {
                destroy();
                mRows = mat.rows();
                mCols = mat.cols();
                if (mRows * mCols > 0) {
                    matrix = new T[mCols * mRows];
                    for (auto i = 0; i < mRows * mCols; i++) {
                        matrix[i] = mat.get_data()[i];
                    }
                } else {
                    matrix = nullptr;
                }
                return *this;
            }

            Mat& operator=(Mat&& mat) {
                destroy();
                mRows = mat.rows();
                mCols = mat.cols();
                if (mRows * mCols > 0) {
                    matrix = new T[mCols * mRows];
                    for (auto i = 0; i < mRows * mCols; i++) {
                        matrix[i] = mat.get_data()[i];
                    }
                } else {
                    matrix = nullptr;
                }
                mat.destroy();
                return *this;
            }
        };

        template<class T>
        Mat<T> square_multiple_o3(Mat<T> a, Mat<T> b) {
            if (a.rows() != a.cols() || b.rows() != b.cols())
                return Mat<T>();
            Mat<T> c(a.rows(), a.cols());
            for (int i = 0; i < a.rows(); i++) {
                for (int j = 0; j < a.cols(); j++) {
                    c.set(0, j, i);
                    for (int k = 0; k < a.rows(); k++) {
                        c.set(c.at(j, i) + a.at(k, i)*b.at(j, k), j, i);
                    }
                }
            }
            return c;
        }
    }
}