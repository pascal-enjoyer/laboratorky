#include <iostream>

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap = 10) {
        arr = new int[cap];
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        size--;

        return value;
    }

    bool is_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == capacity;
    }

    int get_size() {
        return size;
    }

    void print_queue() {
        int count = 0;
        int i = front;
        while (count < size) {
            std::cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print_queue(); // Output: 1 2 3 4 5

    q.enqueue(6); // Output: Queue is full

    std::cout << q.dequeue() << std::endl; // Output: 1

    q.print_queue(); // Output: 2 3 4 5

    std::cout << q.dequeue() << std::endl; // Output: 2

    q.print_queue(); // Output: 3 4 5

    std::cout << "Queue size: " << q.get_size() << std::endl; // Output: Queue size: 3

    return 0;
}