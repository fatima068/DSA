// assume all nodes are unique
// if bst is created in correct order, then in order traversal will print the values in ascending order 
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // for insert, we make 2 functions, 1 that takes array as parameter, other that takes a single value. 
    Node* insertVal(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val); // jab value ki sahi jagah mil jaye, tou create a new node and return. 
        }
        if (val == root->data) {
            cout << "insert only unique values" << endl;
            return root; // dont return nullptr here, kyunke aage jaake rott = func hora, tou root ko nullptr assign hojayega and binary tree will be lost 
        }
        if (val < root->data) {
            root->left = insertVal(root->left, val); // root.left issliye kiya kyunke insert val return karega new node ka address, aur abhi jis node pe khare hain, usske left ptr ko new node pe point karana hai to insert the new node in the binary tree. node.left ke bagher connection create nai hoga
        }
        else {
            root->right = insertVal(root->right, val);
        }
        return root;
    }

    void insertVal(int val[], int n) {
        for (int i = 0; i < n; i++) {
            root = insertVal(root, val[i]);
        }
    }

    Node* minNode(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // to delete a node/value from bst, there is three types of nodes to be considered:
    //1. node with no child
    //2. one child
    //3. two child
    Node* deleteNode(Node* root, int val) { 
        // before deleting, we first have to find the val to be deleted inside our tree, then delete that node and rearrange the tree
        if (root == nullptr) {
            cout << "not found" << endl;
            return root;
        }
        else if (val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        else { // val == root->data (vaue has been found, need to delete it now)
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);             
            }
        }
        return root;
    }
    
    bool search(Node* root, int val) {
        if (root == nullptr) {
            cout << "not found sad" << endl;
            return false;
        }
        if (val < root->data) {
            return search(root->left, val); // yahan pe return karna is zaroori idk how this solves the problem tho. i fink ya tou idhr return karte, ya phir end mei return likhna parta taake backtracking ke waqt kuch return ho as it is a bool function (jaise insertval mei end mei root return kiya kyunke oopar nai hora tha return, over there it was important to assign)
        }
        else if(val > root->data) {
            return search(root->right, val);
        }
        else {
            cout << "value found YAY" << endl;
            return true;
        }
    }

    void inOrder(Node* root) {
        if (root == nullptr) { return; }
        inOrder(root->left);
        cout << root->data << "  ";
        inOrder(root->right);   
    }
}; 

int main() {
    int arr[] = {4, 6, 2, 8, 0, 7, 77, 4, 8, 9};
    BinarySearchTree bst;
    bst.insertVal(arr, 10);
    bst.inOrder(bst.root);
    cout << endl;
    bst.search(bst.root, 88);
    bst.root = bst.deleteNode(bst.root, 4);
    bst.inOrder(bst.root);
}