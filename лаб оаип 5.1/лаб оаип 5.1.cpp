#include <iostream>
#include <cstdlib>
using namespace std;

struct Node { 
    int data;
    Node* next;
};

class HashTable {
private:
    Node** arr;
    int size;
public:
    HashTable(int s) {
        size = s;
        arr = new Node * [size]; 
        for (int i = 0; i < size; i++) {
            arr[i] = nullptr; 
        }
    }

    int hash(int key) { 
        return (key - 53000) % size;
    }

    void insert(int key) { 
        int h = hash(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;
        if (arr[h] == nullptr) {
            arr[h] = newNode;
        }
        else {
            Node* ptr = arr[h];
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void search(int key) { 
        int h = hash(key);
        bool flag = false;
        Node* ptr = arr[h];
        while (ptr != nullptr) {
            if (ptr->data == key) {
                flag = true;
                break;
            }
            ptr = ptr->next;
        }
        if (flag) {
            cout << "Элемент " << key << " найден в хеш-таблице.\n";
        }
        else {
            cout << "Элемент " << key << " не найден в хеш-таблице.\n";
        }
    }

    void display() { 
        for (int i = 0; i < size; i++) {
            cout << i << " || ";
            Node* ptr = arr[i];
            while (ptr != nullptr) {
                cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            cout << "NULL\n";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    int arr[8];
    int lower = 53000, upper = 78000;
    srand(time(0));
    for (int i = 0; i < 8; i++) { 
        arr[i] = rand() % (upper - lower + 1) + lower;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < 8; i++) { 
        cout << arr[i] << " ";
    }
    cout << endl;

    HashTable ht(10); 

    for (int i = 0; i < 8; i++) { 
        ht.insert(arr[i]);
    }

    /*cout << "\nХеш-таблица:\n";
    ht.display(); */

    int key;
    cout << "Введите искомый элемент: ";
    cin >> key;

    ht.search(key); 

    return 0;
}