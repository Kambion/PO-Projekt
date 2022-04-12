#pragma once
#include <vector>

template <typename T>
class Matrix {
private:
    using size_t = std::size_t;

    size_t rows_ = 0, cols_ = 0;
    std::vector<T> content_;
public:
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix() = default;
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
        content_ = std::vector<T>(rows * cols);
    }
    Matrix(size_t rows, size_t cols, const T& initial) : rows_(rows), cols_(cols) {
        content_ = std::vector<T>(rows * cols, initial);
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    size_t size() const { return rows_ * cols_; }
    const std::vector<T>& content() const { return content_; }

    iterator begin() { return std::begin(content_); }
    iterator end() { return std::end(content_); }
    const_iterator begin() const { return cbegin(); }
    const_iterator end() const { return cend(); }
    const_iterator cbegin() const { return std::cbegin(content_); }
    const_iterator cend() const { return std::cend(content_); }

    const T& operator()(size_t row, size_t col) const {
        return content_[row * cols_ + col];
    }

    T& operator()(size_t row, size_t col) {
        return content_[row * cols_ + col];
    }

    const_iterator operator[](size_t row) const {
        return std::cbegin(content_) + (row * cols_);
    }

    iterator operator[](size_t row) {
        return std::begin(content_) + (row * cols_);
    }
};