#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money {
private:
    long rubles;
    int kopecks;
public:
    Money() {
        rubles = 0;
        kopecks = 0;
    }
    Money(long r, int k) {
        rubles = r;
        kopecks = k;
    }
    void setMoney(long r, int k) {
        rubles = r;
        kopecks = k;
    }
    void print() {
        cout << rubles << "," << kopecks << endl;
    }
    Money divide(int divider) {
        long totalKopecks = rubles * 100 + kopecks;
        totalKopecks /= divider;
        long newRubles = totalKopecks / 100;
        int newKopecks = totalKopecks % 100;
        return Money(newRubles, newKopecks);
    }
    Money multiply(double factor) {
        long totalKopecks = rubles * 100 + kopecks;
        totalKopecks *= factor;
        long newRubles = totalKopecks / 100;
        int newKopecks = totalKopecks % 100;
        return Money(newRubles, newKopecks);
    }
    void setRubles(long r) {
        rubles = r;
    }
    void setKopecks(int k) {
        kopecks = k;
    }
    long getRubles() {
        return rubles;
    }
    int getKopecks() {
        return kopecks;
    }
};

void createMoney() {
    Money m;
    long r;
    int k;
    cout << "Enter rubles: ";
    cin >> r;
    cout << "Enter kopecks: ";
    cin >> k;
    m.setMoney(r, k);
    ofstream file("money.txt", ios::app);
    file.write(reinterpret_cast<const char*>(&m), sizeof(m));
    file.close();
    cout << "Money added successfully!" << endl;
}

void viewMoney() {
    ifstream file("money.txt");
    Money m;
    while (file.read(reinterpret_cast<char*>(&m), sizeof(m))) {
        m.print();
    }
    file.close();
}

void deleteMoney() {
    Money m;
    long r;
    int k;
    cout << "Enter rubles: ";
    cin >> r;
    cout << "Enter kopecks: ";
    cin >> k;
    ifstream inFile("money.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&m), sizeof(m))) {
        if (m.getRubles() == r && m.getKopecks() == k) {
            continue;
        }
        outFile.write(reinterpret_cast<const char*>(&m), sizeof(m));
    }
    inFile.close();
    outFile.close();
    remove("money.txt");
    rename("temp.txt", "money.txt");
    cout << "Money deleted successfully!" << endl;
}
void updateMoney() {
    Money m;
    long r, newR;
    int k, newK;
    cout << "Enter rubles to update: ";
    cin >> r;
    cout << "Enter kopecks to update: ";
    cin >> k;
    cout << "Enter new rubles: ";
    cin >> newR;
    cout << "Enter new kopecks: ";
    cin >> newK;
    ifstream inFile("money.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&m), sizeof(m))) {
        if (m.getRubles() == r && m.getKopecks() == k) {
            m.setMoney(newR, newK);
        }
        outFile.write(reinterpret_cast<char*>(&m), sizeof(m));
    }
    inFile.close();
    outFile.close();
    remove("money.txt");
    rename("temp.txt", "money.txt");
    cout << "Update successful!" << endl;
}
void addMoney() {
    Money m;
    long r;
    int k, num;
    cout << "Enter number of elements to add: ";
    cin >> num;
    ofstream outFile("money.txt", ios::binary | ios::app);
    for (int i = 0; i < num; i++) {
        cout << "Enter rubles: ";
        cin >> r;
        cout << "Enter kopecks: ";
        cin >> k;
        m.setRubles(r);
        m.setKopecks(k);
        outFile.write(reinterpret_cast<char*>(&m), sizeof(m));
    }
    outFile.close();
}
void multiplyMoney() {
    Money m;
    float multiplier;
    ifstream inFile("money.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    cout << "Enter multiplier: ";
    cin >> multiplier;
    while (inFile.read(reinterpret_cast<char*>(&m), sizeof(m))) {
        m.multiply(multiplier);
        outFile.write(reinterpret_cast<char*>(&m), sizeof(m));
    }
}
void divideMoney() {
    Money m;
    float divisor;
    ifstream inFile("money.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    cout << "Enter divisor: ";
    cin >> divisor;
    while (inFile.read(reinterpret_cast<char*>(&m), sizeof(m))) {
        m.divide(divisor);
        outFile.write(reinterpret_cast<char*>(&m), sizeof(m));
    }
}
int main() {
    int choice;
    do {
        cout << "\n\nMenu\n";
        cout << "1. Add Money\n";
        cout << "2. View All Money\n";
        cout << "3. Delete Money\n";
        cout << "4. Update Money\n";
        cout << "5. Multiply Money\n";
        cout << "6. Divide Money\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addMoney();
            break;
        case 2:
            viewMoney();
            break;
        case 3:
            deleteMoney();
            break;
        case 4:
            updateMoney();
            break;
        case 5:
            multiplyMoney();
            break;
        case 6:
            divideMoney();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}