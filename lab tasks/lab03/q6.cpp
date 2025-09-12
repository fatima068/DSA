// 6. Flatten a Multilevel Linked List
// Each node has:
// • next pointer (normal linked list connection).
// • child pointer (points to another linked list).
// Write a function to flatten the structure so that all nodes appear in a single-level list.
// • Example:
// • 1 → 2 → 3
// • |
// • 4 → 5
// Output: 1 → 2 → 4 → 5 → 3
#include <iostream>
using namespace std;

class Node{
    public:
    Node *next, *child;
    int val;

    Node(int val) : val(val),next(nullptr), child(nullptr) {}
};
Node* flatten(Node* head);

class linkedList{
    public:
    Node* head;
    Node* tail;
    linkedList() : head(nullptr), tail(nullptr) {}

    void pushback(int val){
        Node* newNode = new Node( val);
        if(tail==nullptr) {
            head=newNode;
            tail = newNode;
            return;
        }
        tail->next= newNode;
        tail = newNode;
    }

    void addChild(int parentVal, int childval){
        Node* temp=head;
        while(temp!= nullptr) {
            if(temp->val ==parentVal) {
                if(temp->child ==nullptr){
                    Node* newnode = new Node(childval);
                    temp->child = newnode;
                    return;
                }
                else {

                    Node* childNode = new Node(childval);
                    Node* childlist = temp->child;
                    while(childlist!=nullptr){
                        if(childlist->next==nullptr) {
                            childlist->next = childNode;
                            return;
                        }
                        childlist = childlist->next;
                    }
                    return;
                }
            }
            temp = temp->next;
        }
        cout <<"parent node not found"<< endl;
    }

    void printMultilevel(Node* head) {
        Node* temp = head;
        while(temp != nullptr){
            if(temp->child==nullptr){
                cout << temp->val <<"    ";
                temp=temp->next;
            } else {
                cout << temp->val <<"    ";
                printMultilevel(temp->child);
                temp=temp->next;
            }
        }
    }

    ~linkedList() {
        this->head=flatten(this->head);
        Node* current = head;
        while(current!=nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete current;
        delete head;
        delete tail;
    }

};

Node* flatten(Node* head) {
    if (head == nullptr) return head;    
    Node* curr = head;
    while(curr!= nullptr){
         if(curr->child != nullptr){
              Node* currNext =curr->next;
              curr->next =flatten(curr->child);
              curr->child=nullptr;

              while(curr->next!=nullptr) {
                curr=curr->next;
              }

              if(currNext!=nullptr) {
                curr->next=currNext;
         }
         curr = curr->next;
        } else {
            curr=curr->next;
        }
    }
    return head;
}

int main() {
    linkedList list;
    list.pushback(1);
    list.pushback(2);
    list.pushback(3);
    list.addChild(2,4);
    list.addChild(2,5);
    list.printMultilevel(list.head);
    cout<<endl;
    list.head = flatten( list.head);
    list.printMultilevel(list.head);

}