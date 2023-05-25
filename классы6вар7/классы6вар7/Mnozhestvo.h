#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Const_iterator.h"
class Mnozhestvo {
private:
    vector<int> data_;

public:
    // Возвращает размер множества
    int size() const {
        return data_.size();
    }

    // Итератор для перебора элементов множества
    const_iterator cbegin() const {
        return const_iterator(data_.cbegin());
    }

    const_iterator cend() const {
        return const_iterator(data_.cend());
    }

    // конструктор по умолчанию
    Mnozhestvo() {}

    // конструктор копирования
    Mnozhestvo(const Mnozhestvo& other) : data_(other.data_) {}

    // оператор присваивания
    Mnozhestvo& operator=(const Mnozhestvo& other) {
        if (this != &other) {
            data_ = other.data_;
        }
        return *this;
    }

    // методы-модификаторы
    void add(int value) {
        if (!contains(value)) {
            data_.push_back(value);
        }
    }

    void remove(int value) {
        data_.erase(std::remove(data_.begin(), data_.end(), value), data_.end());
    }

    // методы-запросы
    bool contains(int value) const {
        return find(data_.begin(), data_.end(), value) != data_.end();
    }

    // операция последовательного доступа
    int& operator[](int index) {
        return data_[index];
    }

    const int& operator[](int index) const {
        return data_[index];
    }

    // операция пересечения множеств
    Mnozhestvo operator*(const Mnozhestvo& other) const {
        Mnozhestvo result;
        for (int i = 0; i < size(); i++) {
            if (other.contains((*this)[i])) {
                result.add((*this)[i]);
            }
        }
        return result;
    }

    // вложенный класс итератора
    class iterator {
    public:
        iterator(vector<int>::iterator it) : it_(it) {}

        int& operator*() {
            return *it_;
        }

        iterator& operator--() {
            --it_;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return it_ == other.it_;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

    private:
        vector<int>::iterator it_;
    };

    // методы, возвращающие итераторы
    iterator begin() {
        return iterator(data_.begin());
    }

    iterator end() {
        return iterator(data_.end());
    }
};
ostream& operator<<(ostream& out, const Mnozhestvo& set) {
    out << "{";
    for (int i = 0; i < set.size(); i++) {
        out << set[i];
        if (i != set.size() - 1) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}