/* Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year Project. This app should allow the users to perform the following operations:

a) Add_Record (): This function will take a string input from user and add into the dictionary. For adding the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate the SUM of ASCII character of that word).

b) Word_Search () User will only pass a single string. If string is not available then generate an error message.

c) Print_Dictionary () Users can also display the complete dictionary.
Note: Use Separate Chaining in case of collisions.
Output:
  -search key AB: FASTNU
  -key EF deleted successfully !
  -index 31: (AB, FASTNU)
  -index 35: (CD, CS) */
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;
    Node(string k,string v) : key(k),value(v),next(nullptr) {}
};

class HashTable{
private:
    Node** buckets;
    int numBuckets;
    
    int hashFunction(string str) {
        int sum = 0;
        for (int i=0; i<str.length(); i++){
            sum +=static_cast<int>(str[i]);
        }
        return sum%numBuckets;
    }

public:
    HashTable(): numBuckets(100) {
        buckets= new Node*[numBuckets];
        for (int i=0; i<numBuckets; i++) {
            buckets[i]= nullptr;
        }
    }
    
    ~HashTable(){
        clear();
        delete[] buckets;
    }
    
    void Add_Record(string key, string word) {
        int index = hashFunction(key);
        Node* current = buckets[index];
        
        while (current != nullptr) {
            if (current->key== key) {
                cout << "key " << key<<" already exists in dictionary" << endl;
                return;
            }
            current = current->next;
        }
        Node* newNode= new Node(key, word);
        newNode->next =buckets[index];
        buckets[index] =newNode;
        
        cout << "key "<<key<< " added successfully at index " <<index << endl;
    }
    
    void Word_Search(string key) {
        int index = hashFunction(key);
        Node* current = buckets[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                cout << "key "<<key << " found: " << current->value<< endl;
                return;
            }
            current = current->next;
        }
        cout<< key << " not found in dictionary"<< endl;
    }
    
    void Print_Dictionary() {
        bool isEmpty = true;        
        for (int i = 0; i < numBuckets; i++) {
            Node* current = buckets[i];
            if (current != nullptr) {
                isEmpty = false;
                cout << "Index " << i << ": ";
                while (current != nullptr) {
                    cout<< current->key<< ", " <<current->value;
                    if (current->next != nullptr)
                        cout << " -> ";
                    current = current->next;
                }
                cout <<endl;
            }
        }
        
        if (isEmpty) {
            cout << "dictionary empty" << endl;
        }
    }
    
    bool Delete_Word(string key) {
        int index = hashFunction(key);
        Node* current = buckets[index];
        Node* prev = nullptr;
        
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    buckets[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                cout <<key << " deleted " << endl;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        cout<< key << " not found "<< endl;
        return false;
    }
    
    void clear() {
        for (int i=0; i<numBuckets; i++) {
            Node* current= buckets[i];
            while (current!= nullptr) {
                Node* temp =current;
                current =current->next;
                delete temp;
            }
            buckets[i]=nullptr;
        }
    }
};

int main() {
    HashTable dictionary;    
    dictionary.Add_Record("AB", "FASTNU");
    dictionary.Add_Record("CD", "CS");
    dictionary.Add_Record("EF", "Computer Science");
    dictionary.Word_Search("AB");
    dictionary.Word_Search("XYZ");
    dictionary.Delete_Word("EF"); 
    cout<< endl << "complete dictionary"<<endl;
    dictionary.Print_Dictionary();
}