// 2. Merge Two Sorted Singly Linked Lists
// Implement a function to merge two sorted singly linked lists into one sorted list.
// • Example:
// o List A: 1 → 3 → 5
// o List B: 2 → 4 → 6
// o Output: 1 → 2 → 3 → 4 → 5 → 6
// • Bonus: Solve without creating new nodes (rearrange pointers).

#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int val;
    Node(int val ): val(val), next(nullptr ) { }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList() :head(nullptr), tail(nullptr) {}

    void pushback(int val ){
        Node* newNode = new Node( val);
        if(tail==nullptr) {
            head=newNode;
            tail = newNode;
            return;
        }
        tail->next= newNode;
        tail = newNode;
    }

    void pushmiddleNode(Node* newNode, int index) {
        if(index ==0) {
            newNode->next= head;
            head = newNode;
            return;
        }
        Node* temp= head;
        for (int i=0; i<index-1; i++) {
            temp= temp->next;
            if(temp== nullptr) {
                cout << "invalid index" << endl;
                return;
            }
        }
        newNode->next=temp->next;
        temp->next = newNode;
        if(tail ==temp)
            tail=newNode;
    }


    void print() {
        Node* temp=head;
        while(temp!= nullptr) {
            cout <<temp->val << " ";
            temp=temp->next;
        }
        cout << endl;
    }

    ~LinkedList(){
        Node* current = head;
        while (current!= nullptr) {
            Node* nextNode =current->next;
            delete current;
            current =nextNode;
        }
    }
};

void merge( LinkedList &list1, LinkedList &list2) {
    if (list1.head==nullptr) {
        list1.head = list2.head;
        list1.tail = list2.tail;
        return;
    }
    if (list2.head==nullptr)
         return;

    Node* list1ptr = list1.head;
    Node* list2ptr= list2.head;
    int val = list2ptr->val;
    int index=-1;
    while(list1ptr!= nullptr ) {
        if(list1ptr->val <=val){
            index++;
            list1ptr = list1ptr->next;
        } else {
            index++;
            list2.head = list2.head->next;
            list1.pushmiddleNode( list2ptr, index);
            list2ptr = list2.head;
            if(list2ptr== nullptr)
                break;
        }
    }
    
    while(list2ptr!= nullptr) {
        list1.tail->next = list2ptr;
        list1.tail = list2ptr;
        list2ptr = list2ptr->next;
    }
}

int main() {
    LinkedList list1;
    list1.pushback(1);
    list1.pushback(3);
    list1.pushback(5);
    list1.pushback(8);
    LinkedList list2;
    list2.pushback(2);
    list2.pushback(4);
    list2.pushback(6);
    merge(list1, list2);
    list1.print();
}