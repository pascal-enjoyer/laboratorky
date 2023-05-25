#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Const_iterator.h"
#include "Mnozhestvo.h"
using namespace std;

int main() {
    Mnozhestvo m1, m2, m3;
    m1.add(1);
    m1.add(2);
    m1.add(3);
    m1.add(4);

    m2.add(3);
    m2.add(4);
    m2.add(5);
    m2.add(6);

    m3 = m1 * m2;

    cout << "Elements of m1: ";
    for (int i = 0; i < m1.size(); i++) {
        cout << m1[i] << " ";
    }
    cout << endl;

    cout << "Elements of m2: ";
    for (int i = 0; i < m2.size(); i++) {
        cout << m2[i] << " ";
    }
    cout << endl;

    cout << "Elements of m3: ";
    for (int i = 0; i < m3.size(); i++) {
        cout << m3[i] << " ";
    }
    cout << endl;

    cout << "Size of vector: " << m1.size() << endl;

    Mnozhestvo::iterator it = m3.end();
    --it;
    cout << "Previous element of m3: " << *it << endl;

    return 0;
}