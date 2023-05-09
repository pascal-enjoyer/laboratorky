#include <iostream>
using namespace std;
class Money {
private:
    long rubles;
    int kopeks;

public:
    Money(long rub, int kop) {
        rubles = rub;
        kopeks = kop;
    }

    void print() {
        cout << rubles << "," << kopeks << endl;
    }

    Money multiply(double num) {
        int newKopeks = static_cast<int>(kopeks * num);
        long newRubles = static_cast<long>(rubles * num) + newKopeks / 100;
        newKopeks = newKopeks % 100;
        return Money(newRubles, newKopeks);
    }

    Money divide(int num) {
        int newKopeks = kopeks / num;
        long newRubles = rubles / num + newKopeks / 100;
        newKopeks = newKopeks % 100;
        return Money(newRubles, newKopeks);
    }

    void removeNotEqual(Money& m) {
        if (rubles != m.rubles || kopeks != m.kopeks) {
            rubles = 0;
            kopeks = 0;
        }
    }

    void reduceByHalf(Money& m) {
        if (rubles == m.rubles && kopeks == m.kopeks) {
            rubles /= 2;
            kopeks /= 2;
        }
    }

    void addEntriesToBeginning(int k) {
        for (int i = 0; i < k; i++) {
            rubles++;
            kopeks++;
        }
    }
};

int main() {
    setlocale(0, "");
    Money m(10, 50);
    cout << "Деньги до умножения: ";
    m.print();
    Money m2 = m.multiply(2.5);
    cout << "Деньги после умножения: ";
    m2.print();

    cout << endl;

    Money m3(100, 80);
    cout << "Деньги до деления: ";
    m3.print();
    Money m4 = m3.divide(4);
    cout << "Деньги после деления: ";
    m4.print();

    cout << endl;

    Money m5(20, 0);
    cout << "Деньги до удалением неравных значений: ";
    m5.print();
    m5.removeNotEqual(m);
    cout << "Деньги после удалением неравных значений: ";
    m5.print();

    cout << endl;

    Money m6(20, 50);
    cout << "Деньги до сокращения наполовину: ";
    m6.print();
    m6.reduceByHalf(m);
    cout << "Деньги после сокращения наполовину: ";
    m6.print();

    cout << endl;

    Money m7(0, 0);
    cout << "Деньги до добавлением значений в начало: ";
    m7.print();
    m7.addEntriesToBeginning(3);
    cout << "Деньги после добавлением значений в начало: ";
    m7.print();

    return 0;
}