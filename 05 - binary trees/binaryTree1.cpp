#include <iostream>
#include <algorithm>
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
        if (root == nullptr) { return; }
        cout << root->data << "  ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }

    void traverseInOrder(Node* root) { // left, root, right (first visit the whole left subtree, then print root, then visit right subtree)
        if (root == nullptr) { return; }
        traverseInOrder(root->left);
        cout << root->data << "  ";
        traverseInOrder(root->right);
    }

    void traversePostOrder(Node* root) { // left right root (first visit root ka pooora left subtree, then poora right subtree, then print the root)
        if (root == nullptr) { return; }
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << "  ";
    }

    int heightOfTree(Node* root) {
        if (root == nullptr) { return 0; }
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int nodeCount(Node* root) {
        if (root ==  nullptr) { return 0; }
        int leftCount = nodeCount(root->left);
        int rightCount = nodeCount(root->right);
        return leftCount + rightCount + 1;
    }

    int sumOfNodes(Node* root) {
        int minVal;
        if (root == nullptr) { return 0; }
        int leftSum = sumOfNodes(root->left);
        int rightSum = sumOfNodes(root->right);
        return leftSum + rightSum + root->data;
    }

    Node* minNode (Node* root) { // works for bst, not for unsorted tree
        if (root->left == nullptr) return root;
        return minNode(root->left);
    }

    void deleteTree(Node* root) {
        // delete left subtree, delete right subtree, delete root
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        cout << "deleteing node: " << root->data << endl;
        root = nullptr;
        delete root;
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
    int preOrder[] = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    BinaryTree tree(buildTreePreOrder(preOrder));
    tree.traversePreOrder(tree.root);
    cout << endl;
    cout << "height: " << tree.heightOfTree(tree.root) << endl;
    cout << "node count: " << tree.nodeCount(tree.root) << endl;
    cout << "sum: " << tree.sumOfNodes(tree.root) << endl;
    Node* minData = tree.minNode(tree.root);
    cout << "min value: " << minData->data << endl;
    tree.deleteTree(tree.root);
    cout << "tree delete yay\nprinting tree after delete\n";
    tree.traversePreOrder(tree.root);
}