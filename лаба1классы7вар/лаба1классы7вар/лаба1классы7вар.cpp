#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

fraction make_fraction(int F, int S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	setlocale(0, "");
	// Определение переменных А и В
	cout << endl << "===”*°•.”*°• ГлАвНое •°*”.•°*”===" << endl;
	fraction A;
	fraction B;
	double X;
	cout << "Введите Х : "; cin >> X;
	A.Init(3, 40);
	B.Read();
	A.Show();
	B.Show();
	cout << endl;
	// Вывод суммы Ax+B
	cout << "Ответ A : " << A.Function(X) << endl;
	cout << "Ответ B : " << B.Function(X) <<endl;

	// Указатели
	cout << endl << "===”*°•.”*°• УкАзАтЕлИ •°*”.•°*”===" << endl;
	fraction* C = new fraction;
	C->Init(0, 0);
	C->Show();
	C->Read();
	C->Function(X);
	cout << "Ответ C : " << C->Function(X) << endl;;

	// Массивы
	cout << endl << "===”*°•.”*°• МаСсИвЫ •°*”.•°*”===" << endl;
	fraction M[2];
	for (int i = 0; i < 2; i++)
	{
		M[i].Read();
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "Результат номер : " << i + 1 << " = " << M[i].Function(X) << endl;
	}

	// Динамические массивы
	cout << endl << "===”*°•.”*°• ДиНаМиЧеСкИе МаСсИвЫ •°*”.•°*”===" << endl;
	int n;
	cout << "N : "; cin >> n;
	fraction* DM = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		DM[i].Read();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Ответ номер : " << i + 1 << " = " << DM[i].Function(X) << endl;
	}
	delete DM;

	// Вызов функции make_fraction
	cout << endl << "===”*°•.”*°• MaKe_FrAcTiOn •°*”.•°*”===" << endl;
	int x, y;
	cout << "Первое >> "; cin >> x;
	cout << "Второе >> "; cin >> y;
	// Формирование переменной(Т) с помощью функции make_fraction
	fraction T = make_fraction(x, y);
	cout <<"Ответ : " << T.Function(X);
}