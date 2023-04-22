#include "Money.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "");
	Money a; // констурктор без параметров
	Money b; // констурктор без параметров
	Money c; // констурктор без параметров
	Money d;
	cin >> a; // ввод
	cin >> b; // ввод
	//++a; // префиксная операция инкремент
	cout << a << endl; // вывод
	c = a / b;
	d = a * b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << " умножение на целое число" << d;
}