#include <iostream>
#include "Vector.h"
#include "Money.h"

using namespace std;

int main() {
    // Создание и заполнение множеств
    Vector<int> s1;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    Vector<int> s2;
    s2.add(2);
    s2.add(3);
    s2.add(4);

    // Вывод содержимого множеств
    cout << "Set 1: ";
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    cout << "Set 2: ";
    for (int i = 0; i < s2.size(); i++) {
        cout << s2[i] << " ";
    }
    cout << endl;

    // Пересечение множеств
    Vector<int> intersection = s1.intersect(s2);
    cout << "Intersection: ";
    for (int i = 0; i < intersection.size(); i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    // Работа с денежными суммами
    Money m1(123, 45);
    Money m2(678, 90);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    Money sum = m1 + m2;
    cout << "m1 + m2 = " << sum << endl;

    return 0;
}