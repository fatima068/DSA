// Write a program to check if a singly linked list is a palindrome.

// •  Input: A singly linked list of integers.
// •  Output: true if the list reads the same forward and backward, false otherwise.
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

    void pushfront(int val) {
        Node* newNode = new Node( val );
        if(head==nullptr) {
            tail=newNode;
        }
        newNode->next= head;
        head=newNode;
    }

    void pusharray(int arr[], int n) {
        for (int i= 0; i<n; i++ ){
            pushfront( arr[i] );
        }
    }

    ~LinkedList(){
        Node* current = head;
        while (current!= nullptr) {
            Node* nextNode =current->next;
            delete current;
            current =nextNode;
        }
        delete current;
        delete head;
        delete tail;
    }
};

bool isPalindrome( LinkedList &list) {
    if(list.head==nullptr || list.head->next==nullptr) 
        return true;
    Node* tempFront = list.head;
    Node* tempBack = list.tail;
    while(tempFront!=tempBack && tempFront->next!= tempBack) {
        if (tempFront->val != tempBack->val) 
            return false;
        tempFront= tempFront->next;
        Node* temp = tempFront;
        while(temp->next !=tempBack) {
            temp = temp->next;
        }
        tempBack = temp;
    }
    return true;
}

int main(){
    LinkedList list;
    
    int arr[] = {1,2,3,2,1,8};
    int n = 6;
    list.pusharray(arr , n);
    if(isPalindrome (list )) {
        cout<<"linked list is palindrome"<<endl;
    } else {
        cout<<"list is not a palindrome"<<endl;
    }


}