#include <iostream>
#include <string>
using namespace std;

#define SIZE 10
struct Node {
    string key;
    Node* next;
};

class HashChaining {
    Node* table[SIZE];

public:
    HashChaining() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    int hash(string key) {
        return key.length() % SIZE;
    }

    void insert(string key) {
        int index = hash(key);
        Node* newNode = new Node{key, table[index]};
        table[index] = newNode;
    }

    bool search(string key) {
        int index = hash(key);
        Node* temp = table[index];
        while (temp) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(string key) {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp) {
            if (temp->key == key) {
                if (prev)
                    prev->next = temp->next;
                else
                    table[index] = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};