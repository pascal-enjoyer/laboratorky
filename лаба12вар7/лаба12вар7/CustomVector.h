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
            std::cout << "������� " << key << " ������ �� ����������.\n";
        }
        else {
            std::cout << "������� " << key << " �� ������ � ����������.\n";
        }
    }

    void performTask3() {
        if (container.empty()) {
            std::cout << "��������� ����. �������� �������� ����� ����������� �������.\n";
            return;
        }

        // ������� ����������� �������
        const T& minElement = *container.begin();

        // ��������� ����������� ������� � ����� ����������
        container.insert(minElement);

        // ������� ������� � �������� ������
        T keyElement; // ����� ����� ������� ��������������� ��� ��� ����� ��������
        auto keyIt = container.find(keyElement);
        if (keyIt != container.end()) {
            // ������� ������� � �������� ������
            container.erase(keyIt);
            std::cout << "������� � ������ " << keyElement << " ������ �� ����������.\n";
        }
        else {
            std::cout << "������� � ������ " << keyElement << " �� ������ � ����������.\n";
        }

        // ��������� ����� ������������ � ������������� ��������� � ������� �������� ����������
        const T& maxElement = *container.rbegin();
        for (auto element : container) {
            element += minElement + maxElement;
        }
    }
};