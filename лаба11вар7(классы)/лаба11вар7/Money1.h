#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// task 2
class Money {
public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) {}

    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }

    void setRubles(long r) { rubles = r; }
    void setKopecks(int k) { kopecks = k; }

    friend bool operator==(const Money& lhs, const Money& rhs) {
        return lhs.rubles == rhs.rubles && lhs.kopecks == rhs.kopecks;
    }

private:
    long rubles;
    int kopecks;
};
