#include "Money.h"
#include <iostream>
using namespace std;
// перегрузка операций присваивания
Money& Money::operator=(const Money& t)
{
	// проверка на самоприсваивание
	if (&t == this) { return *this; }
	rub = t.rub;
	kop = t.kop;
	return *this;
}
// перегрузка префиксной операции инкремент
Money& Money::operator++()
{
	int temp = rub * 100 + kop;
	temp++;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}
// перегрузка постфиксной операции 
Money Money::operator++(int)
{
	int temp = rub * 100 + kop;
	temp++;
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
}
// перегрузка бинарной функции сложения
Money Money::operator/(const Money& t)
{
	float temp1 = rub * 100 + kop;
	float temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 / temp2);
	p.kop = (((temp1 - (p.rub * temp2)) * 10) / temp2);
	return p;
}
Money Money::operator*(const Money& t)
{
	float temp1 = rub * 100 + kop;
	float temp2 = t.rub * 100 + t.kop;
	double temp3 = (temp1 + temp2) * 2.5;
	Money p;
	p.rub = (temp3 / 100);
	p.kop = (temp3 - p.rub * 100);
	return p;
}
// перегрузка глобальной функции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "Vvod rub >> "; in >> t.rub;
	cout << "Vvod kop >> "; in >> t.kop;
	return in;
}
// перегрузка глобальной функции вывода
ostream& operator<<(ostream& out, Money& t)
{
	int sum = t.rub * 100 + t.kop;
	return (out << sum / 100 << "," << sum % 100);
}