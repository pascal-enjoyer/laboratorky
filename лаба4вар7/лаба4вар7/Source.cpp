#include "Header.h"
#include <iostream>
using namespace std;
Pair::Pair(int f, int s) {
	first = f;
	second = s;
}

void Pair::SetFirst(int f) {
	first = f;
}

void Pair::SetSecond(int s) {
	second = s;
}

int Pair::GetFirst() {
	return first;
}

int Pair::GetSecond() {
	return second;
}

Pair Pair::operator+(const Pair& a) {
	
	Pair t;
	t.first = first + a.first;
	t.second = second + a.second;
	return t;
}
Pair Pair :: operator*(const Pair& a) {

	Pair t;
	t.first = first * a.first;
	t.second = second * a.second;
	return t;
}
Pair Pair :: operator-(const Pair& a) {
	Pair t;
	t.first = first - a.first;
	t.second = second - a.second;
	return t;
}
bool Pair :: operator==(const Pair& a)
{
	if ((first == a.first) && (second == a.second)) return true;
	else return false;
}
