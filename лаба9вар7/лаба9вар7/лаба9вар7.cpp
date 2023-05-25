#include <iostream>
#include "Mnozhestvo.h"
using namespace std;
int main() {
        try {
            Mnozhestvo set1, set2;

            // добавляем элементы в set1
            set1 += 10;
            set1 += 20;
            set1 += 30;
            set1 += 40;
            set1 += 50;

            // добавляем элементы в set2
            set2 += 30;
            set2 += 40;
            set2 += 50;
            set2 += 60;
            set2 += 70;

            // выводим элементы set1 и set2
            cout << "set1: ";
            for (int i = 0; i < set1(); i++) {
                cout << set1[i] << " ";
            }
            cout << endl;

            cout << "set2: ";
            for (int i = 0; i < set2(); i++) {
                cout << set2[i] << " ";
            }
            cout << endl;

            // пересечение множеств
            Mnozhestvo intersection = set1 * set2;
            cout << "Intersection: ";
            for (int i = 0; i < intersection(); i++) {
                cout << intersection[i] << " ";
            }
            cout << endl;

            // удаление элемента из set1
            --set1[1];

            // выводим элементы set1 после удаления
            cout << "set1 after deletion: ";
            for (int i = 0; i < set1(); i++) {
                cout << set1[i] << " ";
            }
            cout << endl;

            // доступ по недопустимому индексу
            cout << "Trying to access invalid index..." << endl;
            cout << set1[5] << endl;  // генерирует исключение out_of_range

        }
        catch (const exception& e) {
            cerr << "Exception caught: " << e.what() << endl;
        }
        return 0;
}