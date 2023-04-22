#include <iostream>
#include "Header.h"
using namespace std;
class Rational : public Pair {
private:
	int chislitel;
	int znamenatel;
public:
	Rational(int ch = 0, int zn = 0);

	void setChislitel(int ch);
	void setZnamenatel(int zn);
	int getChislitel();
	int getZnamenatel();
	void checkZnamenatel();

	friend istream& operator>>(istream& is, Rational& s);
};

Rational::Rational(int f, int s) : Pair(f, s) {
	chislitel = f;
	znamenatel = s;
}

void Rational::setChislitel(int ch) {
	chislitel = ch;
}

void Rational::setZnamenatel(int zn) {
	znamenatel = zn;
}

int Rational::getChislitel() {
	return chislitel;
}

int Rational::getZnamenatel() {
	return znamenatel;
}

void Rational::checkZnamenatel() {
	if (znamenatel < 4) {
		cout << "Оценка студента неудовлетворительная!" << endl;
	}
	else {
		cout << "Оценка студента удовлетворительная!" << endl;
	}
}

istream& operator>>(istream& is, Rational& s) {
	int ch, zn;

	cout << "Введите числитель: ";
	is >> ch;
	s.SetFirst(ch);

	cout << "Введите знаменатель: ";
	is >> zn;
	s.SetSecond(zn);
	return is;
}
Rational operator- (const Rational& ch, const Rational& zn) {
	return Rational(ch - zn);
}
Rational operator+ (const Rational& ch, const Rational& zn) {
	return Rational(ch + zn);
}
Rational operator* (const Rational& ch, const Rational& zn) {
	return Rational(ch + zn);
}
int main() {
	Pair a(1, 3);
	Pair b(1, 3);
	Pair c = a - b;
	cout << c.GetFirst();
	cout << " ";
	cout << c.GetSecond();
	cout << "\n\n";
	Pair d = a * b;
	cout << d.GetFirst();
	cout << " ";
	cout << d.GetSecond();
	cout << "\n\n";
	if (a == b) cout << "YA";
	else cout << "NU";
	cout << "\n\n";
	Rational chislo1(10, 5);
	Rational chislo2(5, 5);
	Rational chislo3(chislo1.getChislitel() - chislo2.getChislitel(), chislo1.getZnamenatel() - chislo2.getZnamenatel());
	cout << chislo3.getChislitel() << " " << chislo3.getZnamenatel();
	cout << "\n\n";
	Rational chislo4(chislo1.getChislitel() + chislo2.getChislitel(), chislo1.getZnamenatel() + chislo2.getZnamenatel());
	cout << chislo4.getChislitel() << " " << chislo4.getZnamenatel();
	cout << "\n\n";
	Rational chislo5(chislo1.getChislitel() * chislo2.getChislitel(), chislo1.getZnamenatel() * chislo2.getZnamenatel());
	cout << chislo5.getChislitel() << " " << chislo5.getZnamenatel();
	return 0;
}