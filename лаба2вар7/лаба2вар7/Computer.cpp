#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;
// ����������� ��� ����������
komputer::komputer()
{
	string A = " ";
	B = 0;
	C = 0;
	cout << "Constructor bez parametrov dlya objecta " << this << endl;

}
// ����������� � �����������
komputer::komputer(string a, int b, int c)
{
	A = a;
	B = b;
	C = c;
	cout << "Constructor s parametrami dlya objecta " << this << endl;

}
// ����������� �����������
komputer::komputer(const komputer& t)
{
	A = t.A;
	B = t.B;
	C = t.C;
	cout << "Constructor copirovaniya dlya objecta " << this << endl;
}
// �����������
komputer::~komputer()
{
	cout << "Destructor dlya objecta " << this << endl;
}
// ���������
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
// ������������
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
// �������� ���������
void komputer::show()
{
	cout << "CPU : " << A << endl;
	cout << "RAM : " << B << endl;
	cout << "HDD : " << C << endl;
	cout << endl;
}
