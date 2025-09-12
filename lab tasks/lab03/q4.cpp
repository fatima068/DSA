// 4. Josephus Problem using Circular Linked List

#include<iostream>
using namespace std;

class node{
    public:
    node* next;
    int val;
    node(int val):val(val), next(nullptr) {}
};


class CircularLinkedList{
    public:
    node* head;

    CircularLinkedList() : head(nullptr){}

    void pushfront(int val){
        node* newNode = new node(val);
        if(head==nullptr) {
            head = newNode;
            newNode->next = newNode;
            return;
        }
        node* temp=head;
        while(temp->next!= head){
            temp= temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head= newNode;
    }

    node* deleteMiddle(int index){
        if(head ==nullptr){
            cout<< "list empty" << endl;
            return nullptr;
        }
        if(index<0) {
            cout << "invalid index" << endl;
            return nullptr;
        }
        node* prevNode = head;
        for(int i=0; i<index-1; i++){
            prevNode= prevNode->next;
            if(prevNode==nullptr ||prevNode->next== nullptr) {
                cout << "invalid index" << endl;
                return nullptr;
            }
        }
        node* toDelete = prevNode->next;
        prevNode->next = prevNode->next->next;
        delete toDelete;
        return prevNode->next;
    }

    node* popFront(){
        node* last = head;
        while(last->next!=head){
            last = last->next;
        } 
        node* todelete = head;
        last->next=head->next;
        delete todelete;
        head = last->next;
        return head;
    }


    node* josephusProblem(int k) {
        node* temp = head;
        while (temp != temp->next) {
            for (int count = 1; count < k; count++) {
                temp = temp->next;
            }
            node* toDelete = temp->next;
            if (toDelete == head) {
                head = head->next;
            }
            temp->next = toDelete->next;
            delete toDelete;
        }
        return temp;
    }



};

int main(){
    CircularLinkedList l1;
    l1.pushfront(7);
    l1.pushfront(6);
    l1.pushfront(5);
    l1.pushfront(4);
    l1.pushfront(3);
    l1.pushfront(2);
    l1.pushfront(1);
    
    int k = 3;
    l1.head = l1.josephusProblem(k);
    cout << "survivor: " << l1.head->val;

}