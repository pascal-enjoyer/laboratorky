#pragma once
#include <iostream>
#include <string>
using namespace std;
class komputer
{
	string A;
	int B;
	int C;
public:
	komputer(); // ����������� ��� ����������
	komputer(string, int, int); // ����������� � �����������
	komputer(const komputer&); // ������������ �����������
	~komputer(); // ����������
	string get_A(); // ��������
	void set_A(string); // �����������
	int get_B();
	void set_B(int);
	int get_C();
	void set_C(int);
	void show(); // �������� ���������
};