#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* bubbleSortLinkedList(Node* head) { // swapping nodes
    // Edge cases: empty list or single node → already sorted
    if (head == nullptr || head->next == nullptr) return head;      
    bool swapped = true; // Flag to check if a swap happened in the current pass

    while(swapped == true) { // Keep looping until no swaps happen in a full pass
        Node* temp = head;       // Start traversing from head
        Node* prevNode = nullptr; // Keeps track of the node before 'temp'
        swapped = false;          // Reset swapped flag for this pass

        // Traverse the linked list and compare adjacent nodes
        while (temp->next != nullptr) {
            Node* ptr = temp->next; // Node next to 'temp'

            // If nodes are out of order → swap them
            if (temp->data > ptr->data) {
                swapped = true;  // Mark that a swap occurred

                // Perform swap of 'temp' and 'ptr'
                temp->next = ptr->next;
                ptr->next = temp;

                // If 'temp' was at the head, update head
                if (prevNode == nullptr) {
                    head = ptr;
                } else {
                    prevNode->next = ptr; // Link previous node to new front node
                }

                // After swapping, 'ptr' is before 'temp'
                prevNode = ptr;
            } 
            // If no swap needed, just move forward
            else {
                prevNode = temp;
                temp = temp->next;
            }
        }
    }
    return head;     // Return the head of sorted linked list 
}

int getLength(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++) {
        head = head->next;
    }
    return head;
}
Node* combSortLinkedList(Node* head) { // swapping values 
    if (head !=nullptr || head->next != nullptr) return head; // Edge case: empty or single-node list

    int len = getLength(head);
    int gap = len;
    float shrink = 1.3;
    bool swapped = true;

    // Keep sorting until gap reduces to 1 and no swaps happen
    while (gap > 1 || swapped == true) {
        // Shrink gap
        gap = int(gap / shrink);   // Equivalent to gap / 1.3
        if (gap < 1) gap = 1;

        swapped = false;

        // Compare elements 'gap' apart
        for (int i = 0; i + gap < len; i++) {
            Node* node1 = getNodeAt(head, i);
            Node* node2 = getNodeAt(head, i + gap);

            if (node1->data > node2->data) {
                // Swap their data (simpler than swapping nodes themselves)
                int temp = node1->data;
                node1->data = node2->data;
                node2->data = temp;

                swapped = true;
            }
        }
    }
    return head;
}


Node* insertionSortLinkedList(Node* head) { // swapping nodes
    if (head == nullptr || head->next == nullptr) return head;    // if the list is empty or has only one node, 
    //it is already sorted
    Node* sortedListHead = nullptr; // Pointer to the new sorted list (initially empty)
    Node* current = head;   // Start from the first node of the original list

    while (current != nullptr) {
        Node* nextNode = current->next; // Save the next node before changing pointers

        // Insert current node at the beginning of the sorted list
        if (sortedListHead == nullptr || current->data < sortedListHead->data) {
            current->next = sortedListHead; // Link current node to the previous sorted head
            sortedListHead = current;       // Update sorted list head to current node
        } else {
            // Find the correct position in the sorted list
            Node* temp = sortedListHead;
            while (temp->next !=nullptr && temp->next->data < current->data) {
                temp = temp->next; // Move forward until the right spot is found
            }
            // Insert current node after 'temp'
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode; // Move to the next node in the original list
    }

    return sortedListHead; // Return the head of the new sorted linked list
}

Node* selectionSortLinkedListValues(Node* head) { // swapping nodes
    if (head == nullptr|| head->next == nullptr) return head; // Empty or single-node list

    Node* currentNode = head; // Node we are placing correctly in this iteration(first node of unsorted list )
    while (currentNode != nullptr) {
        Node* minNode = currentNode;      // Assume current node has the minimum value
        Node* temp = currentNode->next; // Node to traverse the unsorted portion

        // Find the node with the minimum value in the unsorted portion
        while (temp != nullptr) {
            if (temp->data < minNode->data) {
                minNode = temp; // Update minNode if a smaller value is found
            }
            temp = temp->next; // Move forward
        }

        // Swap values of currentNode and minNode
        if (minNode != currentNode) {
            int temp = currentNode->data;
            currentNode->data = minNode->data;
            minNode->data = temp;
        }

        currentNode = currentNode->next; // Move to the next node
    }

    return head; // Head stays the same, values are sorted
}


void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
  	
  	// Create a hard-coded linked list:
	// 5 -> 1 -> 32 -> 10 -> 78
    Node *head = new Node(5);
    head->next = new Node(1);
    head->next->next = new Node(32);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(78);
  
    head = bubbleSortLinkedList(head);
    printList(head);
}