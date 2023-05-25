#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Money {
private:
    long rubles;
    int kopecks;
public:
    Money() {
        rubles = 0;
        kopecks = 0;
    }
    Money(long r, int k) {
        rubles = r;
        kopecks = k;
    }
    void setMoney(long r, int k) {
        rubles = r;
        kopecks = k;
    }
    void print() {
        cout << rubles << "," << kopecks << endl;
    }
    Money divide(int divider) {
        long totalKopecks = rubles * 100 + kopecks;
        totalKopecks /= divider;
        long newRubles = totalKopecks / 100;
        int newKopecks = totalKopecks % 100;
        return Money(newRubles, newKopecks);
    }
    Money multiply(double factor) {
        long totalKopecks = rubles * 100 + kopecks;
        totalKopecks *= factor;
        long newRubles = totalKopecks / 100;
        int newKopecks = totalKopecks % 100;
        return Money(newRubles, newKopecks);
    }
    void setRubles(long r) {
        rubles = r;
    }
    void setKopecks(int k) {
        kopecks = k;
    }
    long getRubles() {
        return rubles;
    }
    int getKopecks() {
        return kopecks;
    }
};