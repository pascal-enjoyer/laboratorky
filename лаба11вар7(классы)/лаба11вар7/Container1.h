#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
template<typename T>
class Container
{
public:
    Container() {}
    void add(T element) {
        elements.push_back(element);
    }
    T get(int index) {
        return elements.at(index);
    }
    void remove(int index) {
        elements.erase(elements.begin() + index);
    }
    int size() {
        return elements.size();
    }
    void clear() {
        elements.clear();
    }
private:
    vector<T> elements;
};