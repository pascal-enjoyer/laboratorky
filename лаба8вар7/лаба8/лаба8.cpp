#include <iostream>
#include <fstream>
#include <string>
#include "Stud.h"
using namespace std;

int Proverka(string& str_input, string str_show = "") { 	//функция для проверки введенного пользователем положительного числа >0
	int numeric;
	while (true){
		try {
			cout << str_show; cin >> str_input;
			numeric = stoi(str_input);
			int i, temp = numeric;
			for (i = 0; temp > 0; ++i)
				temp /= 10;
			if (str_input.length() == i) break;
			else { system("cls"); cout << "Ошибка ввода. Повторите попытку.\n\n"; }
		}
		catch (...) { system("cls"); cout << "Ошибка ввода. Повторите попытку.\n\n"; }
	}
	return numeric;
}

void Stud::setFio() { //ввод ФИО (Только слитно)
	cout << "Введите ФИО: ";
	cin >> fio;
}
void Stud::setRating(){ //ввод рейтинга
	string enter_release, show_release;
	show_release = "Введите рейтинг: ";
	rating = to_string(Proverka(enter_release, show_release));
}
void Stud::setAdress(){ //ввод адреса
	cout << "Введите адресс: ";
	cin >> adress;
}
void Stud::setGroup(){	//ввод группы
	cout << "Введите группу: ";
	cin >> group;
}

void fillFile(Stud*& Uchenik, ofstream& fout, const string& path, const int& count){	//заполнение файла из структуры
	fout.open(path);
	for (int i = 0; i < count; ++i)
	{
		fout << "ФИО: " << Uchenik[i].fio << '\n';
		fout << "Рейтинг: " << Uchenik[i].rating << '\n';
		fout << "Адрес: " << Uchenik[i].adress << '\n';
		fout << "Группа: " << Uchenik[i].group;
		if (i != count - 1)
			fout << "\n\n";
	}
	fout.close();
	system("cls"); cout << "Данные о студенте успешно добавлены в файл.\n\n";
}

void removeStuds(Stud*& Uchenik, ofstream& fout, const string& path, int& count){	//удаление элементов, у которых рейтинг меньше заданного
	if (count != 0){
		int* indexStud = new int[count];	//массив со студентами, у которых рейтинг не меньше заданного
		int index = 0;	//количество добавляемых студентов
		bool f = 0;
		string enter_rating, show_rating;
		show_rating = "Введите минимальный рейтинг: ";
		int rating = Proverka(enter_rating, show_rating);
		for (int i = 0; i < count; ++i){
			f = 0;
			if (stoi(Uchenik[i].rating) < rating)	//нахождение студентов, рейтинга 
				f = 1;
			if (f == 0){	//если не нашли, тогда добавляем индекс студента в массив
				indexStud[index] = i;
				++index;
			}
		}
		if (index != count){
			count = index;
			Stud* Uchenik2 = new Stud[index];
			for (int i = 0; i < index; ++i)
				Uchenik2[i] = Uchenik[indexStud[i]];

			delete[] Uchenik;
			Uchenik = Uchenik2;

			fillFile(Uchenik, fout, path, index);
			system("cls"); cout << "Удаление студентов прошло успешно.\n\n";
		}
		else{
			system("cls"); cout << "Нет студентов, рейтинг которых меньше заданного.\n\n";
		}
		delete[] indexStud;
	}
}

void fillStruct(Stud*& Uchenik, const int& count){	//заполнение структуры
	cout << "------------- Студент " << count + 1 << " -------------\n";
	Uchenik[0].setFio();
	Uchenik[0].setRating();
	Uchenik[0].setAdress();
	Uchenik[0].setGroup();
}

void addStudBeginning(Stud*& Uchenik, ofstream& fout, const string& path, int& count){
	const int size = count + 1; //создание размера новой структуры
	Stud* Uchenik2 = new Stud[size];	//новая структура на единицу больше размером, чем предыдущая
	fillStruct(Uchenik2, count);	//добавление нового студента в структуру
	for (int i = 0; i < count; ++i)
		Uchenik2[i + 1] = Uchenik[i];	//переписывание не подходящих студентов из структуры
	delete[] Uchenik;	//удаление старой структуры с заменой на новую
	Uchenik = Uchenik2;
	count += 1;

	fillFile(Uchenik, fout, path, count);	//заполнение файла из структуры
}

void showFile(ifstream& fin, const string& path, int& count){	//вывод данных из файла
	if (count == 0)	//если количество студентов равно 0, выводим соответствующее сообщение
		cout << "Файл пуст!\n\n";
	else {
		fin.open(path);
		if (!fin.is_open()){	//если указан неправильно путь к файлу, выводим соотвутсвующее сообщение
			cout << "Ошибка открытия файла\n";
			return;
		}
		char ch;	//в других случая по байтово считываем информацию в переменную ch, используя цикл while, до тех пор, пока получается считывать данные
		cout << "Студенты, записанные в файле:\n\n";
		while (fin.get(ch))
			cout << ch;
		cout << "\n\n";
		fin.close();
	}
}

int main(){
	system("chcp 1251 >> null");	//изменение кодировки на 1251
	ofstream fout;	//Объявление объекта fout, через который данные будут записывать в файл
	ifstream fin;	//Объявление объекта fin, через который из файла будут считываться данные
	string path = "fileStud.txt";	//путь к файлу
	int count = 0;	//изначальное количество студентов
	Stud* Uchenik = new Stud[count];	//структура с данными студента
	bool f = 1;	//флаг для завершения работы цикла
	while (f){
		string choice_enter,	//переменная для ввода выбора ответа
			choice_show = "Меню:\nВведите 1 - для добавления студента в начало файла\nВведите 2 - для удаления студентов, имеющих рейтинг меньше заданного\nВведите 3 - для вывода данных из файла\nВведите 4 - для завершения работы\n\nВаш выбор ответа: ";	//переменная для вывода работы с меню
		int choice = Proverka(choice_enter, choice_show);	//вызов функции для конвертирования типов данных, если получилось перевести string в int программа пойдет дальше
		cout << "\n";
		switch (choice){
		case 1:
			system("cls");
			addStudBeginning(Uchenik, fout, path, count);	//добавление стдуента в начало файла
			break;
		case 2:
			system("cls");
			showFile(fin, path, count);		//просмотр данных из файла
			removeStuds(Uchenik, fout, path, count);		//удаление студентов, рейтинг которых меньше заданного
			break;
		case 3:
			system("cls");
			showFile(fin, path, count);	//просмотр данных из файла
			break;
		case 4:
			system("cls"); cout << "Конец работы программы.\n";
			f = 0;
			delete[] Uchenik;	//удаления данных из структуры
			break;
		default:
			system("cls"); cout << "Ошибка ввода. Повторите попытку.\n\n";
			break;
		}
	}
	return 0;
}