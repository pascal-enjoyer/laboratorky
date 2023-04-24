#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Mnozhestvo {
private:
    vector<int> v;
public:
    // Возвращает размер множества
int size() const {
    return v.size();

}

// Итератор для перебора элементов множества
class const_iterator {
    std::vector<int>::const_iterator iter;
public:
    const_iterator(std::vector<int>::const_iterator iter) : iter(iter) {}

    const_iterator operator--(int) {
        const_iterator prev = *this;
        iter--;
        return prev;
    }

    const_iterator operator--() {
        iter--;
        return *this;
    }

    int operator*() const {
        return *iter;
    }

    bool operator!=(const const_iterator& other) const {
        return iter != other.iter;
    }
};

const_iterator cbegin() const {
    return const_iterator(v.cbegin());
}

const_iterator cend() const {
    return const_iterator(v.cend());
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

    int size() const {
        return data_.size();
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

private:
    vector<int> data_;
};

// операция вывода в поток
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


int main() {
    Mnozhestvo m1, m2, m3;
    m1.add(1);
    m1.add(2);
    m1.add(3);
    m1.add(4);

    m2.add(3);
    m2.add(4);
    m2.add(5);
    m2.add(6);

    m3 = m1 * m2;

    cout << "Elements of m1: ";
    for (int i = 0; i < m1.size(); i++) {
        cout << m1[i] << " ";
    }
    cout << endl;

    cout << "Elements of m2: ";
    for (int i = 0; i < m2.size(); i++) {
        cout << m2[i] << " ";
    }
    cout << endl;

    cout << "Elements of m3: ";
    for (int i = 0; i < m3.size(); i++) {
        cout << m3[i] << " ";
    }
    cout << endl;

    cout << "Size of vector: " << m1.size() << endl;

    Mnozhestvo::iterator it = m3.end();
    --it;
    cout << "Previous element of m3: " << *it << endl;

    return 0;
}