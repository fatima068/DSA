// AVL trees maintain balance through rotations, ensuring O(log n) time complexity for operations. They prevent BST degradation into linked lists in worst-case scenarios.

// The function returns the new root node after balancing. This is crucial because rotations change the tree's root. The returned node becomes the new root for that subtree, properly maintaining parent-child relationships throughout the recursive calls.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLConverter {
    private:
    int getHeight(Node* node) {
        if (node !=nullptr)
            return node->height;
        return 0;
    }

    int getBalance(Node* node) {
        if (node != nullptr)
            return getHeight(node->left) - getHeight(node->right);
        return 0;
    }
    
    void updateHeight(Node* node) {
        if (node) 
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;    
        Node* t2 = x->right;  
        
        x->right = y;
        y->left = t2;
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    public:
    Node* convertToAVL(Node* root) {
        if (root == nullptr) 
            return nullptr;
        root->left = convertToAVL(root->left);
        root->right = convertToAVL(root->right);
        
        updateHeight(root);
        int balance = getBalance(root);
        
        //LL
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        // RR
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        //LR
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        //RL        
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root; 
    }
};