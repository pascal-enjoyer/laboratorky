#pragma once
#include <iostream>
#include <set>
#include <vector>
template <typename T>
class Vector {
private:
    std::multiset<T> container;

public:
    void addElements3(const std::vector<T>& elements) {
        for (const auto& element : elements) {
            container.insert(element);
        }
    }

    void removeElement3(const T& key) {
        auto it = container.find(key);
        if (it != container.end()) {
            container.erase(it);
            std::cout << "Элемент " << key << " удален из контейнера.\n";
        }
        else {
            std::cout << "Элемент " << key << " не найден в контейнере.\n";
        }
    }

    void performTask3() {
        if (container.empty()) {
            std::cout << "Контейнер пуст. Добавьте элементы перед выполнением задания.\n";
            return;
        }

        // Находим минимальный элемент
        const T& minElement = *container.begin();

        // Добавляем минимальный элемент в конец контейнера
        container.insert(minElement);

        // Находим элемент с заданным ключом
        T keyElement; // Здесь нужно указать соответствующий тип для ключа элемента
        auto keyIt = container.find(keyElement);
        if (keyIt != container.end()) {
            // Удаляем элемент с заданным ключом
            container.erase(keyIt);
            std::cout << "Элемент с ключом " << keyElement << " удален из контейнера.\n";
        }
        else {
            std::cout << "Элемент с ключом " << keyElement << " не найден в контейнере.\n";
        }

        // Добавляем сумму минимального и максимального элементов к каждому элементу контейнера
        const T& maxElement = *container.rbegin();
        for (auto element : container) {
            element += minElement + maxElement;
        }
    }
};