/*Task#4: Find the kth smallest and largest value in the AVL tree and print its key also print both the left side and right side height of the tree starting from root.*/
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
    
    void kthSmallest(Node* node, int& k, int& count, int& result) {
        if (node == nullptr||count >= k)
            return;

        kthSmallest(node->left, k, count,result);  
        count++;
        if (count == k) {
            result = node->key;
            return;
        } 
        kthSmallest(node->right, k, count, result);
    }
    
    void kthLargest(Node* node, int& k, int& count, int& result) {
        if (node == nullptr || count >= k)
            return;

        kthLargest(node->right, k, count, result);
        count++;
        if (count == k) {
            result = node->key;
            return;
        }
        kthLargest(node->left, k, count, result);
    }
};

int main() {
    AVL tree;
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 90);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.inorder(tree.root);
    cout << endl;
    
    int leftHeight = tree.getHeight(tree.root->left);
    int rightHeight = tree.getHeight(tree.root->right);
    cout << "left height: "<< leftHeight << endl;
    cout << "right height: " << rightHeight << endl;

    int k = 3,ksmall = -1, count =0, klarge = -1;
    tree.kthSmallest(tree.root, k, count, ksmall);
    count =0;
    tree.kthLargest(tree.root, k, count, klarge);
    cout << k << " smallest value: " << ksmall << endl;
    cout << k << " largest value: " << klarge << endl;
}