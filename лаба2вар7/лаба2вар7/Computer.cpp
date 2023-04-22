#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;
// конструктор без параметров
komputer::komputer()
{
	string A = " ";
	B = 0;
	C = 0;
	cout << "Constructor bez parametrov dlya objecta " << this << endl;

}
// конструктор с параметрами
komputer::komputer(string a, int b, int c)
{
	A = a;
	B = b;
	C = c;
	cout << "Constructor s parametrami dlya objecta " << this << endl;

}
// конструктор копирования
komputer::komputer(const komputer& t)
{
	A = t.A;
	B = t.B;
	C = t.C;
	cout << "Constructor copirovaniya dlya objecta " << this << endl;
}
// детструктор
komputer::~komputer()
{
	cout << "Destructor dlya objecta " << this << endl;
}
// селекторы
string komputer::get_A()
{
	return A;
}
int komputer::get_B()
{
	return B;
}
int komputer::get_C()
{
	return C;
}
// модификаторы
void komputer::set_A(string a)
{
	A = a;
}
void komputer::set_B(int b)
{
	B = b;
}
void komputer::set_C(int c)
{
	C = C;
}
// просмотр атрибутов
void komputer::show()
{
	cout << "CPU : " << A << endl;
	cout << "RAM : " << B << endl;
	cout << "HDD : " << C << endl;
	cout << endl;
}
