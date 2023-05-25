#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
class Money {
public:
    int rub;
    int kopeks;

    Money(int rub = 0, int kopeks = 0) : rub(rub), kopeks(kopeks) {}

    bool operator<(const Money& other) const {
        if (rub == other.rub)
            return kopeks < other.kopeks;
        return rub < other.rub;
    }

    bool operator==(const Money& other) const {
        return rub == other.rub && kopeks == other.kopeks;
    }
};

// Функция для добавления элементов в контейнер
