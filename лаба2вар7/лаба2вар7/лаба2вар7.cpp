#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;
komputer add_komputer()
{
	string a;
	int b, c;
	cout << "Enter CPU >> ";
	cin >> a;
	cout << "Enter size of RAM  >> ";
	cin >> b;
	cout << "Enter size of HDD >> ";
	cin >> c;
	komputer t(a, b, c);
	return t;
}

void print_komputer(komputer t)
{
	t.show();
}

void main()
{
	// конструктор без параметров
	komputer t1;
	// конструктор с параметром
	komputer t2("intel core i5", 8, 1000);

	komputer t3 = t2;
	t3.set_A("ryzen 5600");
	t3.set_B(4);
	t3.set_C(500);
	// вывод
	print_komputer(t1);
	print_komputer(t2);
	print_komputer(t3);
	t1 = add_komputer();
	t1.show();
}