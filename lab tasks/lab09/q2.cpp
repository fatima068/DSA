/*Task#2: Suppose you have an AVL tree with the following elements: 50, 30, 70, 20, 40, 60, 80. You need to insert a new node with value 55 into the tree and then display the tree after performing a left rotation on the root. Write a C++ code to accomplish this task using the AVLTree class and its methods.*/
#include <iostream>
#include <string>
using namespace std;

int getMax(int a,int b){
    if (a >b)
        return a;
    return b;
}

struct Node{
    int key;
    Node *left, *right;
    int height;
    Node(int val): key(val),left(nullptr), right(nullptr),height(1){}
};

class AVL {
    public:
    Node* root;

    AVL() { root = nullptr; }

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0; 
        return getHeight(node->left) - getHeight(node->right);
    }
    
    Node* rightRotate(Node* node) {
        Node* newRoot = node->left;
        Node* temp = newRoot->right;
        newRoot->right = node;
        node->left = temp;
        node->height = getMax(getHeight(node->left),getHeight(node->right)) + 1;
        newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
        return newRoot;
    }
    
    Node* leftRotate(Node* node) {
        Node* newRoot = node->right;
        Node* temp = newRoot->left;
        newRoot->left = node;
        node->right = temp;
        node->height = getMax(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
        return newRoot;
    }
    
    Node* insert(Node* node, int key) {
        if (node == nullptr)  
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        
        //LL
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        // RR
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        // LR
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }
};


int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);
    tree.inorder(tree.root);
    cout << endl;   

    tree.root = tree.insert(tree.root, 55);
    tree.inorder(tree.root);
}
