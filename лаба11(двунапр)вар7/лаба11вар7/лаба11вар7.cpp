#include <iostream>
#include <fstream>
using namespace std;


class Node
{
    int value;
    Node* prev, * next;

public:
    Node(int VALUE)
    {
        prev = next = NULL;
        value = VALUE;
    }

    Node(Node* PREV, int VALUE)
    {
        prev = PREV;
        prev->next = this;
        next = NULL;
        value = VALUE;
    }

    ~Node()
    {
        if (prev != NULL)
            prev->next = next;
        if (next != NULL)
            next->prev = prev;
    }

    Node* Add(int VALUE)
    {
        next = new Node(this, VALUE);
        return prev;
    }

    void ShowList()
    {
        cout << value << ' ';
        if (next != NULL)
            next->ShowList();
    }

    Node* GetPrev()
    {
        return prev;
    }

    Node* GetNext()
    {
        return next;
    }
};

int main()
{
    setlocale(0, "");
    cout << "Вывести файл(1 или 0)\n";
    int a;
    cin >> a;
    if (a == 1) {
        ifstream fout("file.txt");
        int nam;
        cout << "\n";
        int cnt = 0;
        while (!fout.eof())
        {
            fout >> nam;
            if (nam != 0) {
                cout << nam << " ";
            }
            nam = 0;
        }
        cout << "\n";
        fout.close();
    }
    ofstream fout("file.txt", ios::trunc);
    Node* Begin = NULL, * End = NULL, * Temp;
    char option;
    int i, value;
    int n[10] = {};
    int k = 0, j = 0;
    do
    {
        if (Begin != NULL)
            Begin->ShowList();
        cout << "\n1 - Add to end\n2 - Delete from begin\n3 - Exit\nMy choice: ";
        cin >> option;
        switch (option)
        {
        case '1':
        {
            cout << "Input value: ";
            cin >> value;
            if (End != NULL)
            {
                Temp = new Node(End, value);
                End = Temp;
            }
            else
                Begin = End = new Node(value);
            n[k] = value;
            k++;
        }break;

        case '2':
        {
            if (Begin != NULL)
            {
                Temp = Begin->GetNext();
                delete Begin;
                Begin = Temp;
                if (Begin == NULL)
                    End = NULL;
            }
            n[j] = 0;
            j++;
        }break;
        }
    } while (option != '3');
    for (int i = 0; i < k; i++) {
        fout << n[i] << " ";
    }
    fout.close();
    return 0;
}
