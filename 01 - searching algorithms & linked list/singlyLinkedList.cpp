#include <iostream> 
using namespace std;

class Node {
    public:
    int data;
    Node* next; // store address of next node

    Node(int val) : data(val), next(nullptr) {} // to create a node we need data, cant have empty node. Next can be made to point to head pointer if doing push front etc
};

class SinglyLinkedList {
    private:
    Node* head;
    Node* tail;

    public: 
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void pushFront(int val) {
        Node* newNode = new Node(val); // create a new node first, then add data and next ptr

        if (head == tail && head == nullptr) { //case 1: if list is empty, both head and tail are null
            // this wouldnt have been important if there was no tail pointer. then u can just simply move the head
            head = newNode;
            tail=newNode; // both head and tail will point to this one and only node in the linked list
            newNode->next = nullptr; // as it is the last element, it does not point to any other node hence the nullptr
            return;
        }
        // case 2: if theres already more elements in the list, simply update newNode ka next & head
        newNode->next = head;
        head = newNode;
    }
    
    void pushBack(int val) {
        Node* newNode = new Node(val);
    
        if (head == tail && head == nullptr) { // case 1 same as above
            head = newNode;
            tail=newNode; 
            newNode->next = nullptr;
            return;
        }

        tail->next = newNode; // tail is now second last node instead of last so update pointers accordingly
        newNode->next = nullptr;
        tail = newNode;
    }

    void popFront() {
        if (head == nullptr) {
            cout << "List empty";
            return;
        }

        Node* temp = head; // store the node to be deleted in a temp var
        head = head->next; // move head 1 step aage
        if (head == nullptr) tail = nullptr; // if list becomes empty after pop, update tail to nullptr
        delete temp; // delete the old head
    }

    void popBack() {
        if (head == nullptr) {
            cout <<"List is empty";
            return;
        }
        
        if (head == tail) {  // Only 1 node
            delete head;
            head = tail = nullptr;
            return;
        }
  
        Node* temp = head; // store head in a temp var, then move the temp var to the second last node/PrevNode (as we cant move the head itself: head to aage move kardiya tou there will be no way of going back, so head has to stay in its place)
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;  
        tail->next = nullptr; 
        // delete temp; 
    }

    void pushMiddle(int val, int pos) {
        if (pos < 0) {
            cout << "invalid position" << endl;
            return;
        }

        if (pos == 0) {
            pushFront(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 ; i++) {
            temp = temp->next;
            if (temp == nullptr) {  
                cout << "invalid position" << endl;
                return;
            }
        }
        
        Node* newNode = new Node(val);
        newNode->next = temp->next; 
        temp->next = newNode;
        if (newNode->next == nullptr) { // if newNode is added at the end, update tail
            tail = newNode;
        }
    }

    void popMiddle(int pos) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 0) {
            cout << "invalid position" << endl;
            return;
        }
        if (pos == 0) {
            popFront();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos -1; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "invalid position" << endl;
                return;
            }
        }

        Node* toDelete = temp->next;
        if (temp->next == nullptr) { // user said deleted pos7, tou temp 6 pe aake ruke ga according to normal logic. But ab 7 exist nai karta, tou usske liye alag se check karna parega k 7 nullptr tou nai hai
            cout << "invalid position" << endl;
            return;
        }

        temp->next = temp->next->next; // ab jo node delete karna tha, ussko list se remove kardiya and prevNode(which is temp) usska next ptr update kardiya

        if (temp->next == nullptr) { // if node to be deleted was the last node, update tail, tou isske liye alag se if statement mei check karenge
            tail = temp;
        }

        delete toDelete; 
    }

    Node* findMiddleNode(Node* head, Node* tai) {
        Node* slow = head;
        Node* fast = head;
        while (fast->next !=  tail && fast->next->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void binarySearch(int val) {
        // first find middle node: two methods - we make a helper function to find middle node
        // 1. count the number of nodes, then find middle node by traversing from head
        // 2. use two pointers: slow and fast. slow moves one step, fast moves two steps. When fast reaches the end, slow will be at the middle node
        Node* mid = findMiddleNode(head, nullptr);
        Node* left = head;
        Node* right = tail; // do null ptr if u do not have a tail pointer
        
        while (left <= right) {
            if (mid->data == val) {
                cout << "Element found" << endl;
                return;
            }
            if (mid->data < val) {
                left = mid->next;   
            }
            else {
                right = mid;
            }
            mid = findMiddleNode(left, right);
        }
        cout << "Element not found" << endl;;
    }
    
    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
        // delete temp; DO NOT DELETE TEMP AS IT IS A TRAVERSAL POINTER, NOT A NODE TO BE DELETED
        // temp points to a node at any time so if u dlete temp, a node will get dleted that shouldnt be deleted 
        // u can just set temp to nullptr if u want to free the memory but not delete the node
        cout << endl;
    }

    void reverse() {
        //3 POINTERS: prev(null), curr(head), next(null)
        // 4 STEPS: 
        // 1. Store next node in next ptr (next = curr->next)
        // 2. Reverse current node's pointer  (curr.next = prev)
        // 3. Move prev and curr one step forward (prev = curr, curr = next)
        // 4. Repeat until curr is null (end of list)
        Node* prev = nullptr;
        Node* curr = head;  
        Node* next = nullptr;
        tail = head;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        head = prev;
    }
};

int main() {
    SinglyLinkedList list;
    
   list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);

    cout << "Initial list: ";
    list.print();

    // list.binarySearch(1);
    // list.binarySearch(2);
    list.binarySearch(3); 
    // list.binarySearch(4);
    // list.binarySearch(5);
    // list.binarySearch(6); // Element not found
}

// int main() {
//     SinglyLinkedList list1;
//     list1.pushFront(3);
//     list1.pushFront(2);
//     list1.pushFront(1);
//     list1.pushBack(4);
//     // 3 2 1 4
//     list1.print();

//     list1.pushMiddle(5, 3);        
//     list1.print();

//     list1.popMiddle(3);
//     list1.print();
//     cout << "yay";
// }