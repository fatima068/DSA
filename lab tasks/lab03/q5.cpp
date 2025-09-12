// 5. Convert Between Linked List Types
// Implement functions for conversion:
// 1. Convert a singly linked list into a doubly linked list.
// 2. Convert a singly linked list into a circular linked list.
// • Demonstrate both conversions with sample input lists.
#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node *next, *prev;
    node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class singlyLinkedList{
    public:
    node* head;
    node* tail;
    singlyLinkedList() : head(nullptr), tail(nullptr) {}

    void pushback(int val){
        node* newNode = new node(val);
        if(head== nullptr) {
            head= newNode; 
            tail = newNode;
            return;
        }
        node* temp =head;
        while(temp->next!= nullptr) {
            temp=temp->next;
        }
        temp->next= newNode;
        if(temp=tail)  
            tail=newNode;
    }

    void convertToCircular(){
        if(head==nullptr || head->next==nullptr) 
            return;

        tail->next=head;
    }

    void convertToDoubly() {
        if(head==nullptr || head->next==nullptr) return;

        node* temp1 = head;
        node* temp2=head->next;
        while(temp2!= nullptr) {
            temp2->prev=temp1;
            temp1 =temp1->next;
            temp2=temp2->next;
        }
    }

    void print(){
        node* temp = head;
        while(temp!= nullptr) {
            cout << temp->val << " ";
            temp=temp->next;
            if (temp==head) {
                cout<< temp->val <<endl;
                break;
            }
        }
        cout <<endl;
    }

    void printREverse(){
        node* temp=tail;
        while(temp!= nullptr) {
            cout << temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    ~singlyLinkedList() {
        node* current = head;
        while(current!=nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
        delete current;
        delete head;
        delete tail;
    }
};

int main(){
    singlyLinkedList list1;
    list1.pushback(1);
    list1.pushback(2);
    list1.pushback(3);
    list1.pushback(4);
    list1.pushback(5);
    list1.pushback(6);

    cout <<"list1:";
    list1.print();
    cout<<"list1 circular: ";
    list1.convertToCircular();
    list1.print();

    singlyLinkedList list2;
    list2.pushback(1);
    list2.pushback(2);
    list2.pushback(3);
    list2.pushback(4);
    list2.pushback(5);
    list2.pushback(6);

    cout <<"list2:";
    list2.print();
    cout<<"list2 doubly: ";
    list2.convertToDoubly();
    list2.print();
    cout<<"list2 reverse print: ";
    list2.printREverse();

    
}