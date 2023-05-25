#include <iostream>
#include <set>
#include <vector>
#include "Money1.h"
#include "CustomVector.h"
using namespace std;
// Функция для добавления элементов в контейнер
void addElements1(std::multiset<float>& container) {
    container.insert(3.5);
    container.insert(1.2);
    container.insert(4.7);
    container.insert(2.9);
}

// Функция для удаления элемента из контейнера по заданному значению
void removeElement1(std::multiset<float>& container, float value) {
    auto it = container.find(value);
    if (it != container.end()) {
        container.erase(it);
        std::cout << "Элемент " << value << " удален из контейнера.\n";
    }
    else {
        std::cout << "Элемент " << value << " не найден в контейнере.\n";
    }
}

// Функция для выполнения задания варианта
void performTask1(std::multiset<float>& container) {
    if (container.empty()) {
        std::cout << "Контейнер пуст. Добавьте элементы перед выполнением задания.\n";
        return;
    }

    // Находим минимальный элемент
    float minElement = *container.begin();

    // Добавляем минимальный элемент в конец контейнера
    container.insert(minElement);

    // Находим элемент с заданным ключом и удаляем его
    float key = 4.7;
    removeElement1(container, key);

    // Находим максимальный элемент
    float maxElement = *container.rbegin();

    // Изменяем каждый элемент контейнера, добавляя сумму минимального и максимального элементов
    for (auto it = container.begin(); it != container.end(); ++it) {
        float& value = const_cast<float&>(*it);
        value += minElement + maxElement;
    }
}

// Функция для вывода содержимого контейнера
void printContainer1(const std::multiset<float>& container) {
    std::cout << "Содержимое контейнера:\n";
    for (const auto& value : container) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

void menu() {
    setlocale(0, "");
    std::multiset<float> container;
    int choice;

    do {
        std::cout << "Задача 1: \n\n";
        std::cout << "Меню:\n";
        std::cout << "1. Добавить элементы в контейнер\n";
        std::cout << "2. Удалить элемент из контейнера\n";
        std::cout << "3. Выполнить задание варианта\n";
        std::cout << "4. Вывести содержимое контейнера\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addElements1(container);
            std::cout << "Элементы успешно добавлены в контейнер.\n";
            break;
        case 2: {
            float value;
            std::cout << "Введите значение элемента для удаления: ";
            std::cin >> value;
            removeElement1(container, value);
            break;
        }
        case 3:
            performTask1(container);
            std::cout << "Задание варианта выполнено.\n";
            break;
        case 4:
            printContainer1(container);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        std::cout << '\n';
    } while (choice != 0);
}

// Функция для добавления элементов в контейнер
void addElements2(std::multiset<Money>& container) {
    container.insert(Money(10, 50));
    container.insert(Money(5, 30));
    container.insert(Money(8, 20));
    container.insert(Money(7, 10));
}

// Функция для удаления элемента из контейнера по заданному ключу
void removeElement2(std::multiset<Money>& container, const Money& key) {
    auto it = container.find(key);
    if (it != container.end()) {
        container.erase(it);
        std::cout << "Элемент " << key << " удален из контейнера.\n";
    }
    else {
        std::cout << "Элемент " << key << " не найден в контейнере.\n";
    }
}

// Функция для выполнения задания варианта
void performTask2(std::multiset<Money>& container) {
    if (container.empty()) {
        std::cout << "Контейнер пуст. Добавьте элементы перед выполнением задания.\n";
        return;
    }

    // Находим минимальный элемент
    const Money& minElement = *container.begin();

    // Добавляем минимальный элемент в конец контейнера
    container.insert(minElement);

    // Находим элемент с заданным ключом и удаляем его
    Money key(8, 20);
    removeElement2(container, key);

    // Находим максимальный элемент
    const Money& maxElement = *container.rbegin();

    // Создаем временный контейнер для сохранения измененных элементов
    std::multiset<Money> tempContainer;

    // Добавляем сумму минимального и максимального элементов к каждому элементу контейнера
    for (const auto& money : container) {
        Money updatedMoney = money;
        updatedMoney.rub += minElement.rub + maxElement.rub;
        updatedMoney.kopeks += minElement.kopeks + maxElement.kopeks;

        // Проверяем и корректируем значение копеек, если оно превышает 99
        if (updatedMoney.kopeks > 99) {
            updatedMoney.rub += updatedMoney.kopeks / 100;
            updatedMoney.kopeks %= 100;
        }

        // Добавляем измененный элемент во временный контейнер
        tempContainer.insert(updatedMoney);
    }

    // Заменяем содержимое исходного контейнера на содержимое временного контейнера
    container = tempContainer;
}

// Функция для вывода содержимого контейнера
void printContainer2(const std::multiset<Money>& container) {
    std::cout << "Содержимое контейнера:\n";
    for (const auto& money : container) {
        std::cout << money << '\n';
    }
}

void menu2() {
    std::multiset<Money> container;

    int choice;
    do {
        cout << "Задача 2: \n\n";
        std::cout << "Меню:\n";
        std::cout << "1. Добавить элементы в контейнер\n";
        std::cout << "2. Удалить элемент из контейнера\n";
        std::cout << "3. Выполнить задание варианта\n";
        std::cout << "4. Вывести содержимое контейнера\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addElements2(container);
            std::cout << "Элементы добавлены в контейнер.\n";
            break;
        case 2: {
            int rub, kopeks;
            std::cout << "Введите ключ для удаления (рубли и копейки): ";
            std::cin >> rub >> kopeks;
            removeElement2(container, Money(rub, kopeks));
            break;
        }
        case 3:
            performTask2(container);
            std::cout << "Задание выполнено.\n";
            break;
        case 4:
            printContainer2(container);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        std::cout << '\n';
    } while (choice != 0);
}



void menu3() {
    Vector<int> vec;

    // Заполнение контейнера элементами
    std::vector<int> elements = { 5, 2, 8, 1, 9 };
    vec.addElements3(elements);

    int choice;
    do {
        cout << "Задача 3: \n\n";
        // Вывод меню и обработка выбора пользователя
        std::cout << "Меню:\n";
        std::cout << "1. Добавить элементы\n";
        std::cout << "2. Удалить элемент по ключу\n";
        std::cout << "3. Выполнить задание\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите номер операции: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            vector<int> newElements;
            // Ввод новых элементов
            // ...
            vec.addElements3(newElements);
            break;
        }
        case 2: {
            int key;
            // Ввод ключа элемента для удаления
            // ...
            vec.removeElement3(key);
            break;
        }
        case 3: {
            vec.performTask3();
            break;
        }
        case 0: {
            std::cout << "Программа завершена.\n";
            break;
        }
        default: {
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 0);
}

int main() {
    setlocale(0, "");
    menu();
    menu2();
    menu3();
    return 0;
}