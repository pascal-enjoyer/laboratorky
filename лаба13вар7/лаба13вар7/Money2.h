#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


class Money2 {
public:
    int rub;
    int kopeks;

    Money2(int rub = 0, int kopeks = 0) : rub(rub), kopeks(kopeks) {}


    bool operator<(const Money2& other) const {
        if (rub == other.rub)
            return kopeks < other.kopeks;
        return rub < other.rub;
    }
};
bool operator==(const Money2& lhs, const Money2& rhs) {
    return lhs.rub == rhs.rub && lhs.kopeks == rhs.kopeks;
}
bool operator!=(const Money2& lhs, const Money2& rhs) {
    return !(lhs == rhs);
}
bool operator>(const Money2& lhs, const Money2& rhs) {
    if (lhs.rub == rhs.rub)
        return lhs.kopeks > rhs.kopeks;
    return lhs.rub > rhs.rub;
}
