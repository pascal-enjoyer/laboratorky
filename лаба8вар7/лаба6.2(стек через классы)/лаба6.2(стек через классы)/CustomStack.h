#pragma once
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    T peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
