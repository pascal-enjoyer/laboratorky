#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair {
private:
	int first;
	int second;

public:
	Pair()
	{

	}
	Pair(int f, int s);
	void SetFirst(int f);
	void SetSecond(int s);
	int GetFirst();
	int GetSecond();
	Pair operator+(const Pair& a);
	Pair operator*(const Pair&);
	Pair operator-(const Pair&);
	bool operator==(const Pair&);
};