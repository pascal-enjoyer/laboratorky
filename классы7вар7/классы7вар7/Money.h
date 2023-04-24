#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
    long m_rubles;
    int m_kopecks;

public:
    Money() : m_rubles(0), m_kopecks(0) {}
    Money(long rubles, int kopecks) : m_rubles(rubles), m_kopecks(kopecks) {}

    long rubles() const {
        return m_rubles;
    }

    int kopecks() const {
        return m_kopecks;
    }

    void setRubles(long rubles) {
        m_rubles = rubles;
    }

    void setKopecks(int kopecks) {
        m_kopecks = kopecks;
    }

    void add(const Money& other) {
        m_rubles += other.m_rubles;
        m_kopecks += other.m_kopecks;
        if (m_kopecks >= 100) {
            m_rubles += m_kopecks / 100;
            m_kopecks %= 100;
        }
    }

    Money operator+(const Money& other) const {
        Money result(*this);
        result.add(other);
        return result;
    }

    Money& operator+=(const Money& other) {
        add(other);
        return *this;
    }

    bool operator==(const Money& other) const {
        return m_rubles == other.m_rubles && m_kopecks == other.m_kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.m_rubles << ',' << (money.m_kopecks < 10 ? "0" : "") << money.m_kopecks;
        return os;
    }
};

#endif // MONEY_H