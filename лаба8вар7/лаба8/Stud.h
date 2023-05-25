#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct Stud {
	void setFio();
	void setRating();	//сигнатуры методов
	void setAdress();
	void setGroup();
	string fio;
	string rating;
	string adress;	//переменные структуры
	string group;
};
