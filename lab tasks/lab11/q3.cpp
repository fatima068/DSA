// Implement the class Hash class having the functionality of insert, delete, search and display using list (built in library for linked list in C++).
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Hash {
    private:
    list<pair<string, string> >* table;
    int size;
    
    int getHash(string key){
        int sum =0;
        for (int i=0; i<key.length();i++)
            sum+= key[i];

        return sum%size;
    }

    public:
    Hash(int size=10): size(size) {table = new list<pair<string, string> >[size]; }
    
    ~Hash() { delete[] table; }

    void insert(string key,string value){
        int index =getHash(key);
        list<pair<string, string> > newList;
        bool keyFound = false;
        
        while (table[index].empty() == false) {
            pair<string, string> front =table[index].front();
            table[index].pop_front();
            if (front.first == key){
                newList.push_front(make_pair(key, value));
                keyFound = true;
            } 
            else {newList.push_front(front); }
        }
        if (keyFound ==false) { newList.push_front(make_pair(key, value));}
        table[index] = newList;
    }
    
    void deleteKey(string key) {
        int index =getHash(key);
        list<pair<string, string> > newList;
        
        while (table[index].empty()== false){
            pair<string, string> front =table[index].front();
            table[index].pop_front();
            if (front.first !=key){
                newList.push_front(front);
            }
        }
        table[index] =newList;
    }
    
    string search(string key){
        int index =getHash(key);
        list<pair<string,string>> temp=table[index];
        
        while (temp.empty() ==false) {
            pair<string, string> front= temp.front();
            temp.pop_front();
            if (front.first== key) {
                return front.second;
            }
        }
        return "not found";
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "index "<< i<<": ";
            list<pair<string, string> > temp=table[i];
            while (temp.empty() ==false) {
                pair<string,string> front= temp.front();
                temp.pop_front();
                cout<< front.first << ", " << front.second;
            }
            cout<< endl;
        }
    }
};

int main() {
    Hash h;
    h.insert("apple","fruit");
    h.insert("banana","fruit"); 
    h.insert("carrot","vegetable");
    h.insert("dog","animal");
    cout << "Hash Table:" <<endl;
    h.display();
    cout <<endl<< h.search("apple") << endl;
    cout << endl<< h.search("cat") << endl;
    h.deleteKey("banana");
    cout <<endl<< "deleted banana: "<<endl;
    h.display();
    h.insert("apple","red fruit");
    cout<<endl<< "updating apple: "<<endl;
    h.display();
}