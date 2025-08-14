#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    int height;
    Node* right;
    Node* left;

    Node(int val) : data(val), height(1), right(nullptr), left(nullptr) {}
};

class avlTree {
    public:
    Node* root;

    avlTree() : root(nullptr) {}

    Node* LLrotation (Node* root) {
        Node* newRoot = root->left;
        Node* newRootRight = newRoot->right;
        // rotate now 
        newRoot->left = root;
        root->left = newRootRight;
        return newRoot;
    }

    Node* RRrotation (Node* root) { // new root aur new root ke left ko alag pointer mei store karna hai
        Node* newRoot = root->right;
        Node* newRootLeft = newRoot->left;
        // now do rotation: new root assign ho chuki hai, need to update new root ka left to old root, and old root ka right to newrootleft
        newRoot->left = root;
        root->right = newRootLeft;
        return newRoot;
    }

    int getBalanceFactor (Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return getHeight(root->left) - getHeight(root->right);
    }

    int getHeight(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        int rightHeight = getHeight(root->right);
        int leftHeight = getHeight(root->left);
        return max(leftHeight, rightHeight) + 1;
    }

    Node* minNode(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* insert(Node* root, int val) { // insert new node and return value of new root
        // Node* newNode = new Node(val); // dont have to do this, create new node sirf insert karte time hee
        if (root == nullptr) {
            Node* newNode = new Node(val);
            return newNode;
        } else if (val < root->data) {
            root->left = insert(root->left, val);
        }
        else if (val > root->data) {
            root->right = insert(root->right, val);
        }
        else {
            cout << "insert only unique values" << endl;
            return root;
        }
        // ab node insert ho chuka hai, backtracking ke waqt ye code run hoga, starting from the leaf node and going towards root
        // check if every node is balanced here. bf nikalen ge sabka 
        int bf = getBalanceFactor(root);

        if (bf > 1 && val < root->left->data) { // LL imbalance case
            return LLrotation(root);
        } 
        else if (bf > 1 && val > root->left->data) { // LR imbalance case 
            root->left = RRrotation(root->left);
            return LLrotation(root);
        } 
        else if (bf < -1 && val > root->right->data) { // RR imbalance case 
            return RRrotation(root);
        } 
        else if (bf < -1 && val < root->right->data) { //RL imbalance case
            root->right = LLrotation(root->right);
            return RRrotation(root);
        }
        return root; // return the final root of the avl tree after it has been balanced
    }

    Node* deleteNode(Node* root, int val) {
        if (root == nullptr) {
            cout << "not found" << endl;
            return root; 
        }
        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        else { // vaue/node to delete has been found, usse delete karenge ab. first we see the 3 deletion cases (leaf node, 1 child, 2 child)
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
        // node delete hogya, now we check if tree is balanced 
        int bf = getBalanceFactor(root);
        if (bf == 2 && getBalanceFactor(root->left) >= 0) { //LL
            return LLrotation(root);
        }
        else if (bf == 2 && getBalanceFactor(root->left) < 0) { //LR
            root->left = RRrotation(root->left);
            return LLrotation(root);
        }
        else if (bf == -2 && getBalanceFactor(root->right) <= 0) { //RR
            return RRrotation(root);
        }
        else if (bf == -2 && getBalanceFactor(root->right) > 0) { //RL
            root->right = LLrotation(root->right);
            return RRrotation(root);
        }
        return root;
    }

    void traverseInOrder(Node* root) { // left, orint root, right
        if (root == nullptr) {
            return;
        }
        traverseInOrder(root->left);
        cout << root->data << "   ";
        traverseInOrder(root->right);
    }
};

int main () {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 6);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 77);
    int h = avl.getHeight(avl.root);
    cout << "height: " << h << endl << endl;
    avl.traverseInOrder(avl.root);
}