#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Task 1
void add_min_to_end(vector<float>& vec) {
    float min_val = *min_element(vec.begin(), vec.end());
    vec.push_back(min_val);
}

void remove_value(vector<float>& vec, float val) {
    vec.erase(remove(vec.begin(), vec.end(), val), vec.end());
}

void add_sum_of_min_max(vector<float>& vec) {
    float min_val = *min_element(vec.begin(), vec.end());
    float max_val = *max_element(vec.begin(), vec.end());
    float sum = min_val + max_val;
    for (float& elem : vec) {
        elem += sum;
    }
}

// Task 2
class Money {
public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) {}

    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }

    void setRubles(long r) { rubles = r; }
    void setKopecks(int k) { kopecks = k; }

    friend bool operator==(const Money& lhs, const Money& rhs) {
        return lhs.rubles == rhs.rubles && lhs.kopecks == rhs.kopecks;
    }

private:
    long rubles;
    int kopecks;
};

void add_min_value(deque<Money>& v) {
    Money minVal;
    bool first = true;
    for (const Money& m : v) {
        if (first || m.getRubles() < minVal.getRubles() ||
            (m.getRubles() == minVal.getRubles() && m.getKopecks() < minVal.getKopecks())) {
            minVal = m;
            first = false;
        }
    }
    v.push_back(minVal);
}

void remove_money(queue<Money>& q, long rubles, int kopecks) {
    queue<Money> temp;
    while (!q.empty()) {
        if (!(q.front().getRubles() == rubles && q.front().getKopecks() == kopecks)) {
            temp.push(q.front());
        }
        q.pop();
    }
    q = temp;
}

void add_sum_of_min_max(deque<Money>& q) {
    Money minVal;
    Money maxVal;
    bool first = true;
    for (const Money& m : q) {
        if (first || m.getRubles() < minVal.getRubles() ||
            (m.getRubles() == minVal.getRubles() && m.getKopecks() < minVal.getKopecks())) {
            minVal = m;
        }
        if (first || m.getRubles() > maxVal.getRubles() ||
            (m.getRubles() == maxVal.getRubles() && m.getKopecks() > maxVal.getKopecks())) {
            maxVal = m;
        }
        first = false;
    }
    for (Money& m : q) {
        m.setRubles(m.getRubles() + minVal.getRubles() + maxVal.getRubles());
        m.setKopecks(m.getKopecks() + minVal.getKopecks() + maxVal.getKopecks());
    }
}

template<typename T>
class Container
{
public:
    Container() {}
    void add(T element);
    T get(int index);
    void remove(int index);
    int size();
    void clear();
private:
    std::vector<T> elements;
};
template<typename T>
void Container<T>::add(T element) {
    elements.push_back(element);
}

template<typename T>
T Container<T>::get(int index) {
    return elements.at(index);
}

template<typename T>
void Container<T>::remove(int index) {
    elements.erase(elements.begin() + index);
}

template<typename T>
int Container<T>::size() {
    return elements.size();
}

template<typename T>
void Container<T>::clear() {
    elements.clear();
}
int main()
{
    Container<int> container;
    int choice;
    int value;
    int index;
    do
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add an element" << std::endl;
        std::cout << "2. Get an element" << std::endl;
        std::cout << "3. Remove an element" << std::endl;
        std::cout << "4. Get the size" << std::endl;
        std::cout << "5. Clear the container" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the value to add: ";
            std::cin >> value;
            container.add(value);
            break;
        case 2:
            std::cout << "Enter the index of the element to get: ";
            std::cin >> index;
            std::cout << "Element at index " << index << " is " << container.get(index) << std::endl;
            break;
        case 3:
            std::cout << "Enter the index of the element to remove: ";
            std::cin >> index;
            container.remove(index);
            break;
        case 4:
            std::cout << "Size of container is " << container.size() << std::endl;
            break;
        case 5:
            container.clear();
            std::cout << "Container cleared." << std::endl;
            break;
        case 6:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
            break;
        }
    } while (choice != 6);
    return 0;
}