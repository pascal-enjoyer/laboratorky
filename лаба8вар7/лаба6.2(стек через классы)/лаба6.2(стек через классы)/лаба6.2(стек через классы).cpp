#include <iostream>
#include "CustomStack.h"

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.isEmpty() << std::endl;
    return 0;
}

//В данной реализации стека с помощью односвязного списка создается класс Stack, содержащий приватное поле top, указывающее на вершину стека.
//Внутренний класс Node используется для хранения данных элемента стека и указателя на следующий элемент.
//Метод push добавляет новый элемент на вершину стека.
//Метод pop удаляет элемент с вершины стека и возвращает его значение.Метод peek возвращает значение элемента на вершине стека, не удаляя его.
//Метод isEmpty проверяет, пуст ли стек.