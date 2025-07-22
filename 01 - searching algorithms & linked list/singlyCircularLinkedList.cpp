// needs only a tail pointer to implement
// tail.next = head; is the basic condition of a circular linked list
// if u do not have a head pointer, u can use tail.next (because tail ka next is always the head)
// if u do not have a tail pointer, idk youre doomed

#include <iostream>
using namespace std;    

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularSinglyLinkedList {
    private:
    Node* tail;

    public:
    CircularSinglyLinkedList() : tail(nullptr) {}

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) { // ie the list is empty
            tail = newNode;
            tail->next = newNode; // can also do tail.next = tail; because tail points to itself as it is the only node
            return;
        } 
        newNode->next = tail->next; // dont do newnode.next = tail as it will cause error (idk what error tho i dont get it)
        tail->next = newNode; // tail.next is basically head, and as we are inserting at head, we need to update tail's next pointer to point to the new node
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            // can use insertAtHead here
            tail = newNode;
            tail->next = newNode; // dont have to do newnode.next alag se becuase tail is the new node, tou wo ussi ke saath hogya 
            return;   
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void popAtHead() { // 3 cases (empty list, 1 node, and multiple nodes)
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (tail == tail->next) { // only 1 node exists
            delete tail;
            tail = nullptr;
            return;
        }

        Node* temp = tail->next;
        tail->next = temp->next; // or tail.next = tail->next->next;
        delete temp;
    }

    void popAtTail() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (tail == tail->next) { // only 1 node exists
            delete tail;
            tail = nullptr;
            return;
        }

        Node* toDelete = tail; // store the node to be deleted, then find the previous node, so it can become the new tail
        Node* prevNode = tail->next;
        while(prevNode->next != tail) {
            prevNode = prevNode->next;
        }
        prevNode->next = tail->next;
        tail = prevNode;
        delete toDelete;
    }

    void pushMiddle(int val, int pos) {
        // 2. list has only 1 node
        // 3. list has multiple nodes 
        // need to see if case 2 and 3 are the same
         if (pos == 0 || tail == nullptr) {
            insertAtHead(val);
            return;
         }
         if (pos < 0) {
            cout << "Invalid position." << endl;
            return;
         }
         Node* temp = tail->next; 
         for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == tail->next) { // because issmei null ptr nai hota after tail, it just goes to head 
                cout << "invalid position." << endl;
                return;
            }
         }
         if (temp == tail) {
             insertAtTail(val);
             return;
            }
        Node* newNode = new Node(val);
         newNode->next = temp->next;
         temp->next = newNode;
    }

    void popMiddle(int pos) {
        if (pos < 0) {
            cout << "invalid position";
            return;
        }
        if (tail == nullptr) {
            cout << "list empty";
            return;
        }
        if (pos == 0) {
            popAtHead();
            return;
        }
        
        Node* temp = tail->next;
        for (int i = 0; i <pos - 1; i++) {
            temp = temp->next;
            if (temp == tail) {
                cout << "invalid position";
                return;
            }
        }
        // are we popping the tail? adjust tail ptr accordingly
        // else pop normal
        Node* toDelete = temp->next; // 5 10 15
        if (toDelete == tail) {
            popAtTail();
            // temp->next = tail->next;
            // tail = temp;
            // delete toDelete;
            return;
        }
        temp->next = temp->next->next;
        delete toDelete;
    }
        

    void print() { 
        if(tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* head = tail->next; // get the head in a temporary variable
        cout << head->data << " "; // head ka data output karke ek position aage move kardiya
        head = head->next;
        while (head != tail->next) { // ab jab tak wo pointer wapis tail.next yaani ke head pe nai aajata, tab tak it will print the data in the list
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main() {
    CircularSinglyLinkedList list;
    
    // Build list: 10 -> 20 -> 30 -> 40
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Original list: ";
    list.print();  // 10 20 30 40

    // Test 1: Invalid positions
    cout << "\nTest invalid positions:\n";
    list.popMiddle(-1);  // Invalid position
    list.popMiddle(4);   // Invalid position (size is 4, max valid is 3)
    cout << "List remains: ";
    list.print();

    // Test 2: Delete middle (position 1: 20)
    cout << "\nDelete middle (position 1):\n";
    list.popMiddle(1);
    cout << "Expected: 10 30 40 | Actual: ";
    list.print();

    // Test 3: Delete new tail (position 2: 40)
    cout << "\nDelete tail (position 2):\n";
    list.popMiddle(2);
    cout << "Expected: 10 30 | Actual: ";
    list.print();

    // Test 4: Delete head (position 0)
    cout << "\nDelete head (position 0):\n";
    list.popMiddle(0);
    cout << "Expected: 30 | Actual: ";
    list.print();

    // Test 5: Delete last remaining node
    cout << "\nDelete last node (position 0):\n";
    list.popMiddle(0);
    cout << "Expected: List is empty | Actual: ";
    list.print();

    return 0;
}