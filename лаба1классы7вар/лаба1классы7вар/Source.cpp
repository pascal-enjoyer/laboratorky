#include <iostream>
#include "Header.h"
using namespace std;

// ����� ������������� ����� ���������
void fraction::Init(int F, int S)
{
	first = F;
	second = S;
}

// ����� ��� ������ �������� �����
void fraction::Read()
{
	cout << endl << "������ >> "; cin >> first;
	cout << "������ >> "; cin >> second;
}

// ����� ��� ������ �������� �����
void fraction::Show()
{
	cout << endl << "������ = " << first;
	cout << endl << "������ = " << second;
	cout << endl;
}

// ����� ��� ���������� �����
double fraction::Function(double X)
{
	return (X * first + second);
}
