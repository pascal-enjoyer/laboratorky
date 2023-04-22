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
	komputer(); // конструктор без параметров
	komputer(string, int, int); // конструктор с параметрами
	komputer(const komputer&); // консутруктор копирования
	~komputer(); // деструктор
	string get_A(); // селектор
	void set_A(string); // модификатор
	int get_B();
	void set_B(int);
	int get_C();
	void set_C(int);
	void show(); // просмотр атрибутов
};