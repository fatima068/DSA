#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class doublyLinkedList {
    private:
    Node* head;
    Node* tail;

    public:
    doublyLinkedList() : head(nullptr), tail(nullptr) {}

    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (head == tail && head == nullptr) { // if the list is initially empty
            head = newNode;
            tail = newNode;
            return;
        }
        // if the list is not empty
        newNode->next = head;
        head->prev = newNode;  
        head = newNode;
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == tail && head == nullptr) { // if the list is initially empty
            head = newNode;
            tail = newNode;
            return;
        }
        // if the list is not empty
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode; 
    }

    void popFront() {
        if (head == nullptr) {
            cout <<"list empty" << endl;
            return;
        }
        Node* toDelete = head; // store the node to be deleted in a toDelete var
        head = head->next; 
        if (head == nullptr) { // if the list becomes empty (ie there was only one node)
            tail = nullptr;
            delete toDelete;
            return;
        }

        head->prev = nullptr;
        toDelete->next = nullptr;
        delete toDelete;
    }

    void popBack() {
        if (head == nullptr) {
            cout << "list empty" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) { // if the list becomes empty (ie there was only one node)
            head = nullptr;
            delete temp;
            return;
        }
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    void pushMiddle(int val, int pos) {
        if(pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0 || (head == nullptr && tail == nullptr)) {
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

        if (temp->next == nullptr) {
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
            return; // or call pushback
        }
        temp->next->prev = newNode; 
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
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
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == nullptr || temp->next == nullptr) { // kyunke temp is basically prevNode, agar temp khud null hojata hai ya usske agla waala node doesnt exist tou pop kaise hoga
                cout << "invalid position" << endl;
                return;
            }
        }

        Node* toDelete = temp->next;

        temp->next = temp->next->next; // yahan pe remove the connection of temp with the node to be deleted
        if (temp->next == nullptr) { // node delete karne ke baad usski jagah agar ek aur node nai hai but nullptr hai, matlab we deleted the last node, hence we need to update tail 
            tail = temp;
            delete toDelete;
            return;
        }
        
        // agar tail node nai tha tou agle node ka prev pointer update karna parega
        temp->next->prev = temp;
        delete toDelete; 
    }

    void print(){
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " " ;
            temp = temp->next;
        }
    }
};

int main() {
    doublyLinkedList dll;

    cout << "========== Testing popMiddle() ==========\n\n";

    // Test 1: Empty list
    cout << "Test 1: popMiddle from empty list\n";
    cout << "Expected: List is empty | Actual: ";
    dll.popMiddle(0);
    cout << "\n";

    // Build a list: 100 -> 200 -> 300 -> 400 -> 500
    dll.pushBack(100);
    dll.pushBack(200);
    dll.pushBack(300);
    dll.pushBack(400);
    dll.pushBack(500);
    cout << "Initial list: ";
    dll.print();
    cout << "\n\n";

    // Test 2: Invalid negative position
    cout << "Test 2: popMiddle(-1)\n";
    cout << "Expected: invalid position | Actual: ";
    dll.popMiddle(-1);
    dll.print();
    cout << "\n\n";

    // Test 3: Position 0 (head)
    cout << "Test 3: popMiddle(0) (remove head)\n";
    cout << "Expected: 200 300 400 500 | Actual: ";
    dll.popMiddle(0);
    dll.print();
    cout << "\n";


    // Test 4: Last position (tail)
    cout << "Test 4: popMiddle(3) (remove tail)\n";
    cout << "Expected: 200 300 400 | Actual: ";
    dll.popMiddle(3);
    dll.print();
    cout << "\n";

    // Test 5: Middle position
    cout << "Test 5: popMiddle(1) (remove middle)\n";
    cout << "Expected: 200 400 | Actual: ";
    dll.popMiddle(1);
    dll.print();
    cout << "\n";

    // Test 6: Invalid large position
    cout << "Test 6: popMiddle(10)\n";
    cout << "Expected: invalid position | Actual: ";
    dll.popMiddle(10);
    dll.print();
    cout << "\n\n";

    // Test 7: Single node remaining
    cout << "Test 7: popMiddle(0) (last node)\n";
    dll.popMiddle(0);
    cout << "Expected: List is empty | Actual: ";
    dll.print();
    cout << "\n";

    // Test 8: popMiddle on empty list again
    cout << "Test 8: popMiddle(0) on empty list\n";
    cout << "Expected: List is empty | Actual: ";
    dll.popMiddle(0);
    cout << "\n";

    dll.popMiddle(0); // This line seems to be a mistake, as it is not defined in the context of this code. It should be removed or replaced with a valid function call.

}