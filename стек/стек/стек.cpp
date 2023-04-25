#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100; // максимальный размер стека
    int top_index; // индекс вершины стека
    int arr[MAX_SIZE]; // массив элементов стека

public:
    Stack() { top_index = -1; } // конструктор, инициализирующий вершину стека как пустую

    bool isEmpty() { return top_index < 0; } // метод, проверяющий, является ли стек пустым

    bool push(int value) { // метод, добавляющий элемент на вершину стека
        if (top_index >= MAX_SIZE - 1) return false; // если стек уже полный, то добавить новый элемент не удастся
        arr[++top_index] = value;
        return true;
    }

    bool pop() { // метод, удаляющий элемент с вершины стека
        if (isEmpty()) return false; // если стек уже пустой, то удалить элемент не удастся
        top_index--;
        return true;
    }

    int top() { return arr[top_index]; } // метод, возвращающий элемент, находящийся на вершине стека
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}