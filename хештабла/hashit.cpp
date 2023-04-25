/*     6 var
* key - address (string)
* data -> FIO, Num passport, address
* Hash - func -> H(k) = [M(kAmod1)], 0 < A < 1, mod1 - получение дробной части, [] - получение целой части
* Метод открытой адресации + метод цепочек
*/

// Метод открытой адресации
#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

// FIO
string surnames[5] = { "Лебедев", "Соколов", "Зайцев", "Голубев", "Козлов" };
string name[5] = { "Виктор", "Иван", "Захар", "Пётр", "Архип" };
string patronymic[5] = { "Алексеевич", "Игоревич", "Олегович", "Денисович", "Романович" };


// address
string city[5] = { "Москва", "Омск", "Екатеринбург", "Воронеж", "Новосибирск" };
string street[5] = { "Ленина", "Карла Маркса", "Советская", "Мира", "Свободы" };

vector <int> collisions = { -1 }; // заполнили несуществующим значением индекса
int col = 0; // количество коллизий

struct Data         // необходимые дынные об 1ом объекте 
{
    string FIO;
    string address;
    string passport;
    Data()                  //значения по умолчанию
    {
        FIO = "NULL";
        address = "NULL";
        passport = "NULL";
    }
};

string get_FIO()
{
    return surnames[rand() % 5] + " " + name[rand() % 5] + " " + patronymic[rand() % 5]; //извлекаем рандомный индекс из массивов фамилий, имён, отчеств
}

string get_ADD()
{
    return "г. " + city[rand() % 5] + ", ул. " + street[rand() % 5] + " - " + to_string(rand() % 160 + 10);//извлекаем рандомный индекс из массивов городов и улиц + номер дома
}

string get_num_passport()
{
    return to_string(rand() % 999999 + 111111);
}

Data create_person() //создание и заполнение массива структур
{
    Data person;

    person.FIO = get_FIO();
    person.address = get_ADD();
    person.passport = get_num_passport();

    return person;
}

struct HashTab
{
    Data* mas;
    int size;
    HashTab(const int size)    //конструктор
    {
        this->size = size;
        mas = new Data[this->size];

    }
    ~HashTab()     //деструктор
    {
        delete[] mas;
    }

    bool is_empty_elem(int index) const; // проверка ячейки на пустоту. const -  указывает на то, что эта функция не изменяет состояние объекта.
    bool is_empty_tab(const int size) const;
    int Hash_Func(string key, const int size);
    int Hash_Func_for_insert(string key, const int size);
    void insert(Data person, const int size); //вставка элемента по индексу
    void remove(string key, const int size); // удаление элемента
    void searchElem(string key, const int size); // поиск индекса по элементу
    void FillingTable(const int size); //полное заполнение ХТ
    void Delete(const int size); // удаление данных из ХТ
    void printTable();
};

int get_sum_ADD(string add)     //получение суммы символов по таблице ASCII
{
    int sum = 0;
    for (int i = 0; i < add.size(); i++)
    {
        sum += (int)(unsigned char(add[i]));
    }
    return sum;
}

bool HashTab::is_empty_elem(int index) const
{
    bool res = false;
    if (mas[index].FIO == "NULL" and mas[index].address == "NULL" and mas[index].passport == "NULL")
        res = true;
    return res;
}

bool HashTab::is_empty_tab(const int size) const
{
    bool res = false;
    int i = 0;
    while (res == false and i < size)
    {
        if (mas[i].FIO == "NULL" and mas[i].address == "NULL" and mas[i].passport == "NULL")
            res = true;
        i++;
    }
    return res;
}

vector <int> INDEX_HF;

void Index_HF() //просмотр всех индексов, которые выдавала ХФ
{
    for (int i = 0; i < INDEX_HF.size(); i++)
        cout << "Res HF: " << INDEX_HF[i] << endl;
}

int HashTab::Hash_Func_for_insert(string key, const int size)
{
    double ka = (sqrt(3) - 1) * get_sum_ADD(key);
    double double_ka = ka - static_cast<int>(ka); // получение дробной части от ka
    double res = size * double_ka;
    INDEX_HF.push_back(static_cast<int>(res));
    if (!(find(collisions.begin(), collisions.end(), static_cast<int>(res)) != collisions.end())) // проверка итератором вектора для подсчета коллизий
        // если выданного результатат нет в векторе, то добавляем, если есть, то +1 коллизия
        collisions.push_back(static_cast<int>(res));
    else
    {
        col++;
    }
    return static_cast<int>(res);       // получение целой части от переменной res

}

int HashTab::Hash_Func(string key, const int size)
{
    double ka = (sqrt(3) - 1) * get_sum_ADD(key);
    double double_ka = ka - static_cast<int>(ka); // получение дробной части от ka
    double res = size * double_ka;
    return static_cast<int>(res);       // получение целой части от переменной res

}

void HashTab::printTable()
{
    for (int i = 0; i < size; i++)
    {
        cout << "____________________________________________________________" << endl;
        cout << "ФИО: " << mas[i].FIO << endl;
        cout << "Место проживания: " << mas[i].address << endl;
        cout << "Номер паспорта: " << mas[i].passport << endl;
    }
}

void HashTab::insert(Data person, const int size)
{
    int index = Hash_Func_for_insert(person.address, size);
    int tmp = index; // переменная, хранящее первое значение выданное ХФ
    if (is_empty_elem(index))
    {
        mas[index] = person;
    }
    else
    {
        while (index < size)
        {
            if (is_empty_elem(index))
            {
                mas[index] = person;
                break;
            }
            else
            {
                index++;
            }
        }
        if (index >= size)
        {
            index = 0;
            while (index < tmp)
            {
                if (is_empty_elem(index))
                {
                    mas[index] = person;
                    break;
                }
                else
                {
                    index++;
                }
            }
            if (index >= tmp)
            {
                cout << "Добавление невозможно! Нет свободных ячеек в таблице!" << endl;
            }

        }
    }
}

void HashTab::remove(string key, const int size) // удаление элемента
{
    int index = Hash_Func(key, size);
    int tmp = index; // переменная, хранящее первое значение выданное ХФ
    if (mas[index].address == key)
    {
        mas[index] = Data(); // значение по умолчанию NULL
        return;
    }
    else
    {
        while (index < size)
        {
            if (mas[index].address == key)
            {
                mas[index] = Data();
                return;
            }
            index++;

        }
        if (index >= size)
        {
            index = 0;
            while (index < tmp)
            {
                if (mas[index].address == key)
                {
                    mas[index] = Data();
                    return;
                }
                index++;
            }
            if (index >= tmp)
                cout << "Удаление невозможно! Человека с таким адресом не существует в таблице!" << endl;
        }
    }
}

void HashTab::searchElem(string key, const int size)
{
    int index = Hash_Func(key, size);
    int tmp = index; // переменная, хранящее первое значение выданное ХФ
    if (key == mas[index].address)
    {
        cout << "Человек, проживающий по адресу " << key << " записан под индексом " << index << endl;
        return;
    }
    while (index < size and key != mas[index].address)
    {
        index++;
    }
    if (index >= size)
    {
        index = 0;
        while (index < tmp and key != mas[index].address)
        {
            index++;
        }
        if (index >= tmp)
        {
            cout << "Человек с адресом " << key << " не занесён в таблицу!" << endl;
            return;
        }
        else
        {
            cout << "Человек, проживающий по адресу " << key << " записан под индексом " << index << endl;
            return;
        }

    }
    else
    {
        cout << "Человек, проживающий по адресу " << key << " записан под индексом " << index << endl;
        return;
    }

}

void HashTab::FillingTable(const int size)
{
    for (int i = 0; i < size; i++)
        insert(create_person(), size);
}

void HashTab::Delete(const int size)
{
    bool fl = is_empty_tab(size);
    if (fl)
        cout << "Отсутствуют элементы для удаления! Таблица уже пуста!" << endl;
    else
    {
        for (int i = 0; i < size; i++)
            mas[i] = Data();
        col = 0;
        collisions = { -1 };
        INDEX_HF = {};
    }

}

void print_menu() {
    system("cls"); // очищаем экран
    cout << "ЧТО ВЫ ХОТИТЕ СДЕЛАТЬ?" << endl << endl;

    cout << "\t\t\t\tХЕШ - ТАБЛИЦА" << endl << endl;

    cout << "1. Добавить элемент в ХТ." << endl;
    cout << "2. Удалить элемент из ХТ." << endl;
    cout << "3. Получить индекс элемента." << endl;
    cout << "4. Узнать результаты выполнения ХФ" << endl;
    cout << "5. Узнать количество коллизий." << endl;
    cout << "6. Заполнить ХТ полностью." << endl;
    cout << "7. Очистить данные из ХТ." << endl;
    cout << "8. Вывести ХТ в консоль." << endl;
    cout << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << endl;

    cout << "9. Выход" << endl;
    cout << ">> ";
}

int get_var(int count)
{
    int var;
    cin >> var;
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (var < 1 or var > count) {
        cout << "НЕКОРРЕКТНЫЙ ВВОД! ПОПРОБУЙТЕ СНОВА " << endl; // выводим сообщение об ошибке
        system("pause");
        cout << ">> ";
        cin >> var; // считываем строку повторно
    }
    return var;
}

int main()
{
    system("chcp 1251>NULL");
    srand(time(NULL));

    int var;

    int N; // размер hash - функции
    cout << "Enter N: ";
    cin >> N;
    print_menu();
    HashTab Tab(N);
    string CITY_, STREET_, NUM_;
    string keys;

    do {
        print_menu(); // выводим меню на экран

        var = get_var(9); // получаем номер выбранного пункта меню

        switch (var)
        {
        case 1:
            Tab.insert(create_person(), N);
            break;

        case 2:
            cout << "Введите город: ";
            getline(cin, CITY_);
            getline(cin, CITY_);
            cout << "Введите улицу: ";
            getline(cin, STREET_);
            cout << "Введите номер дома: ";
            getline(cin, NUM_);
            keys = "г. " + CITY_ + ", ул. " + STREET_ + " - " + NUM_;
            Tab.remove(keys, N);
            break;

        case 3:
            cout << "Введите город: ";
            getline(cin, CITY_);
            getline(cin, CITY_);
            cout << "Введите улицу: ";
            getline(cin, STREET_);
            cout << "Введите номер дома: ";
            getline(cin, NUM_);
            keys = "г. " + CITY_ + ", ул. " + STREET_ + " - " + NUM_;
            Tab.searchElem(keys, N);
            break;

        case 4:
            Index_HF();
            break;

        case 5:
            cout << "Количество коллизий: " << col << endl;
            break;

        case 6:
            Tab.FillingTable(N);
            break;

        case 7:
            Tab.Delete(N);
            break;

        case 8:
            Tab.printTable();
            break;

        }

        if (var != 9)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (var != 9);

    return 0;
}