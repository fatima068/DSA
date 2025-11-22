/*Task # 1: Suppose you are working on a program that needs to store a large number of strings, with the possibility of duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the ASCII values of the characters in the string and returns the remainder after dividing by the number of buckets. You decide to implement the hash table using a linked list for each bucket.*/
#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string key;
    string value;
    Node* next;
    Node(string k, string v): key(k),value(v),next(nullptr) {}
};

class HashTable {
private:
    Node** buckets;
    int numBuckets;
    
    int hashFunction(string str) {
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum +=static_cast<int>(str[i]);
        }
        return sum%numBuckets;
    }

public:
    HashTable(int size=10): numBuckets(size) {
        buckets = new Node*[numBuckets];
        for (int i = 0; i<numBuckets;i++) {
            buckets[i]= nullptr;
        }
    }
    
    ~HashTable() {
        clear();
        delete[] buckets;
    }
    
    void insert(string key, string value) {
        int index = hashFunction(key);
        Node* current = buckets[index];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "Key "<< key <<" already exists. Updating value from " << current->value << " to " << value << "' in bucket "<<index<<endl;
                current->value=value;
                return;
            }
            current=current->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        
        cout <<"Inserted key "<<key<< " with value " <<value <<" in bucket " <<index << endl;
    }
    
    string search(string key) {
        int index = hashFunction(key);
        Node* current = buckets[index];
        
        while (current != nullptr){
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return"Key not found";
    }
    
    bool remove(string key) {
        int index= hashFunction(key);
        Node* current =buckets[index];
        Node* prev =nullptr;
        
        while (current!=nullptr) {
            if (current->key== key) {
                if (prev ==nullptr) {buckets[index] = current->next;} 
                else {  prev->next = current->next;}
                cout << "Removed key "<< key << "from bucket "<<index << endl;
                delete current;
                return true;
            }
            prev = current;
            current= current->next;
        }
        
        cout <<key <<" not found" << endl;
        return false;
    }
    
    void display() {
        cout << endl<< "hash table:" << endl;        
        for (int i=0; i<numBuckets; i++) {
            cout << "bucket " << i<<": ";
            Node* current = buckets[i];
            if (current == nullptr) { cout << "Empty"; } 
            else {
                while (current != nullptr) {
                    cout  << current->key << ":" << current->value;
                    if (current->next != nullptr) {
                        cout << " -> ";
                    }
                    current= current->next;
                }
            }
            cout<< endl;
        }
    }
    
    void clear() {
        for (int i = 0; i < numBuckets; i++) {
            Node* current= buckets[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            buckets[i] = nullptr;
        }
    }
};

int main() {
    HashTable myhash(10); 
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();
    cout <<"search for keyA: " << myhash.search("A") << endl;
    myhash.remove("B");
    cout << "after removing key B: "<<endl;
    myhash.display();
}