#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
template<typename T>
class Vector
{
public:
    Vector() : size_(0), capacity_(10), elements_(new T[capacity_]) {}
    ~Vector() { delete[] elements_; }

    void add(const T& element);
    int size() const { return size_; }
    T operator[](int index) const { return elements_[index]; }
    Vector<T> intersect(const Vector<T>& other) const;

private:
    int size_;
    int capacity_;
    T* elements_;
};
template<typename T>
void Vector<T>::add(const T& element) {
    for (int i = 0; i < size_; i++) {
        if (elements_[i] == element) {
            return;
        }
    }

    if (size_ >= capacity_) {
        capacity_ *= 2;
        T* newElements = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            newElements[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = newElements;
    }

    elements_[size_] = element;
    size_++;
}

template<typename T>
Vector<T> Vector<T>::intersect(const Vector<T>& other) const {
    Vector<T> result;
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < other.size(); j++) {
            if (elements_[i] == other[j]) {
                result.add(elements_[i]);
                break;
            }
        }
    }
    return result;
}

#endif // VECTOR_H


