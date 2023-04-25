#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person() {}
    virtual ~Person() {}

    virtual void input() = 0;
    virtual void output() const = 0;
};

class Student : public Person {
public:
    Student() {}
    ~Student() {}

    void input() override {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter rating: ";
        cin >> rating;
    }

    void output() const override {
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
    }

    void createGroup(int size) {
        capacity = size;
        group = new Student[size];
        cout << "Group created with " << size << " students." << endl;
    }

    void addStudent() {
        if (size == capacity) {
            cout << "Group is full." << endl;
            return;
        }

        Student student;
        student.input();
        group[size] = student;
        size++;
        cout << "Student added to group." << endl;
    }

    void removeStudent() {
        int index;
        cout << "Enter index of student to remove: ";
        cin >> index;

        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            group[i] = group[i + 1];
        }

        size--;
        cout << "Student removed from group." << endl;
    }

    void printGroup() const {
        cout << "Group:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "] ";
            group[i].output();
        }
    }

    void printStudentName(int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }

        cout << "Name of student at index " << index << ": " << group[index].getName() << endl;
    }
    Student* group = nullptr;
private:
    string name;
    float rating;
    int size = 0;
    int capacity = 0;

    string getName() const { return name; }
};

int main() {
    Student student;
    student.createGroup(3);

    char command;
    do {
        cout << "Enter command: ";
        cin >> command;

        switch (command) {
        case 'm': {
            int size;
            cout << "Enter size of group: ";
            cin >> size;
            student.createGroup(size);
            break;
        }
        case '+':
            student.addStudent();
            break;
        case '-':
            student.removeStudent();
            break;
        case 's':
            student.printGroup();
            break;
        case 'z': {
            int index;
            cout << "Enter index: ";
            cin >> index;
            student.printStudentName(index);
            break;
        }
        case 'q':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid command." << endl;
            break;
        }
    } while (command != 'q');

    delete[] student.group;

    return 0;
}
