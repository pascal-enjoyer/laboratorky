#pragma once
#include <iostream>
class Mnozhestvo {
private:
    int* data;   // ������ ��� �������� ��������� ���������
    int size;    // ������ ���������
public:
    Mnozhestvo() {   // ����������� �� ���������
        size = 0;
        data = nullptr;
    }
    Mnozhestvo(const Mnozhestvo& other) {   // ����������� �����������
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    ~Mnozhestvo() {   // ����������
        delete[] data;
    }
    int operator[](int index) const {   // �������� ������� �� �������
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    int& operator[](int index) {   // �������� ������� �� ������� (��� ������)
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    int operator()() const {   // �������� ����������� ������� �������
        return size;
    }
    Mnozhestvo operator*(const Mnozhestvo& other) const {   // �������� ����������� ��������
        Mnozhestvo result;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                if (data[i] == other.data[j]) {
                    result += data[i];
                }
            }
        }
        return result;
    }
    Mnozhestvo& operator--() {   // �������� �������� �������� �� ���������
        if (size == 0) {
            throw logic_error("Set is empty");
        }
        size--;
        return *this;
    }
    Mnozhestvo& operator+=(int value) {   // �������� ���������� �������� � ���������
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                throw invalid_argument("Element already exists in set");
            }
        }
        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        new_data[size] = value;
        size++;
        delete[] data;
        data = new_data;
        return *this;
    }
    Mnozhestvo& operator-=(int value) {   // �������� �������� �������� �� ���������
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                found = true;
                for (int j = i; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                size--;
                break;
            }
        }
    }
};