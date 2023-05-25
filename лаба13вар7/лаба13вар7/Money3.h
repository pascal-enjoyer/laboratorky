#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


struct Money3 {
    int rub;
    int kopeks;

    Money3(int rub = 0, int kopeks = 0) : rub(rub), kopeks(kopeks) {}
};

bool operator<(const Money3& lhs, const Money3& rhs) {
    if (lhs.rub < rhs.rub) {
        return true;
    }
    else if (lhs.rub == rhs.rub) {
        return lhs.kopeks < rhs.kopeks;
    }
    return false;
}

bool operator==(const Money3& lhs, const Money3& rhs) {
    return lhs.rub == rhs.rub && lhs.kopeks == rhs.kopeks;
}