#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Money1.h"
#include "Container1.h"

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



int main()
{
    Container<int> container;
    int choice;
    int value;
    int index;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Add an element" << endl;
        cout << "2. Get an element" << endl;
        cout << "3. Remove an element" << endl;
        cout << "4. Get the size" << endl;
        cout << "5. Clear the container" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to add: ";
            cin >> value;
            container.add(value);
            break;
        case 2:
            cout << "Enter the index of the element to get: ";
            cin >> index;
            cout << "Element at index " << index << " is " << container.get(index) << endl;
            break;
        case 3:
            cout << "Enter the index of the element to remove: ";
            cin >> index;
            container.remove(index);
            break;
        case 4:
            cout << "Size of container is " << container.size() << endl;
            break;
        case 5:
            container.clear();
            cout << "Container cleared." << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}