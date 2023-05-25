#pragma once
#include <iostream>
#include <set>
#include <vector>
struct Money {
    int rub;
    int kopeks;

    Money(int rub = 0, int kopeks = 0) : rub(rub), kopeks(kopeks) {}

    // ���������� ��������� < ��� ��������� ��������� Money
    bool operator<(const Money& other) const {
        if (rub != other.rub) {
            return rub < other.rub;
        }
        return kopeks < other.kopeks;
    }

    // ���������� ��������� << ��� ������ ��������� Money
    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.rub << " ���. " << money.kopeks << " ���.";
        return os;
    }
};