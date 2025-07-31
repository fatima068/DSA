#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data) : data(data), right(nullptr), left(nullptr) {}
};

class BinaryTree {
    public:
    Node* root;

    BinaryTree(Node* root) : root(root) {}

    void traversePreOrder(Node* root) { // root, left, right (print root, visit left subtree, visit right subtree)
        if (root == nullptr) {
            return;
        }
        cout << root->data << "  ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }

    void traverseInOrder(Node* root) { // left, root, right (first visit the whole left subtree, then print root, then visit right subtree)
        if (root == nullptr) {
            return;
        }
        traverseInOrder(root->left);
        cout << root->data << "  ";
        traverseInOrder(root->right);
    }

    void traversePostOrder(Node* root) { // left right root (first visit root ka pooora left subtree, then poora right subtree, then print the root)
        if (root == nullptr) {
            return;
        }
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << "  ";
    }
};

static int idx = -1;

Node* buildTreePreOrder(int preOrder[]) {
    idx++;
    if (preOrder[idx] == -1) {
        return nullptr;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTreePreOrder(preOrder);
    root->right = buildTreePreOrder(preOrder);
    return root;
}

int main() {
    int preOrder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    BinaryTree tree(buildTreePreOrder(preOrder));
    tree.traversePreOrder(tree.root);
    cout << endl;
    tree.traverseInOrder(tree.root);
    cout << endl;
    tree.traversePostOrder(tree.root);
}