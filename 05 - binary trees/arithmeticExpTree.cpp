#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Node structure
struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string val) : value(val), left(NULL), right(NULL) {}
};

// Utility: Check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to build an Arithmetic Expression Tree from an infix expression
Node* buildTree(string &expression) {
    stack<Node*> nodes;   // Stack to hold operand nodes (numbers, variables, or subtrees)
    stack<char> ops;      // Stack to hold operators (+, -, *, /, and parentheses)

    // Loop through each character of the infix expression
    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];

        // Skip spaces
        if (c == ' ') continue;

        // ---------------------------------------------------------
        // CASE 1: Opening parenthesis '('
        // ---------------------------------------------------------
        // This marks the start of a sub-expression
        // Push it to the operator stack to know where this subexpression ends
        if (c == '(') {
            ops.push(c);
        }

        // ---------------------------------------------------------
        // CASE 2: Operand (a variable or a digit)
        // ---------------------------------------------------------
        // If the character is alphanumeric (like 'a', '1', etc.)
        // Create a node for it and push it to the node stack
        else if (isalnum(c)) {
            string operand(1, c);           // Convert char → string
            nodes.push(new Node(operand));  // Push as a new leaf node
        }

        // ---------------------------------------------------------
        // CASE 3: Closing parenthesis ')'
        // ---------------------------------------------------------
        // This means the current sub-expression is complete.
        // So pop operators until we find '(' and build subtrees.
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                // Pop the top operator
                char op = ops.top(); 
                ops.pop();

                // Pop the top two operand nodes to form a subtree
                Node* right = nodes.top(); nodes.pop();
                Node* left = nodes.top(); nodes.pop();

                // Create a new internal node with this operator
                Node* newNode = new Node(string(1, op));
                newNode->left = left;
                newNode->right = right;

                // Push the newly formed subtree back to the node stack
                nodes.push(newNode);
            }

            // Remove the '(' from operator stack (we’re done with this subexpression)
            ops.pop();
        }

        // ---------------------------------------------------------
        // CASE 4: Operator (+, -, *, /)
        // ---------------------------------------------------------
        else if (isOperator(c)) {
            // If there’s an operator on the stack with higher or equal precedence,
            // we must first complete that operation before pushing the new one.
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                // Pop the higher-precedence operator
                char op = ops.top(); 
                ops.pop();

                // Pop top two nodes (operands) and make a subtree
                Node* right = nodes.top(); nodes.pop();
                Node* left = nodes.top(); nodes.pop();

                Node* newNode = new Node(string(1, op));
                newNode->left = left;
                newNode->right = right;

                // Push the subtree back
                nodes.push(newNode);
            }

            // Finally, push the current operator onto the stack
            ops.push(c);
        }
    }

    // ---------------------------------------------------------
    // CASE 5: After processing the full expression
    // ---------------------------------------------------------
    // If any operators are still left in the operator stack,
    // build subtrees from them as well.
    while (!ops.empty()) {
        char op = ops.top(); 
        ops.pop();

        Node* right = nodes.top(); nodes.pop();
        Node* left = nodes.top(); nodes.pop();

        Node* newNode = new Node(string(1, op));
        newNode->left = left;
        newNode->right = right;

        nodes.push(newNode);
    }

    // ---------------------------------------------------------
    // FINAL RESULT:
    // The remaining node in 'nodes' stack is the root of the expression tree
    // ---------------------------------------------------------
    return nodes.top();
}

// Inorder traversal to print expression
void inorder(Node* root) {
    if (!root) return;
    bool isOp = isOperator(root->value[0]);
    if (isOp) cout << "(";
    inorder(root->left);
    cout << root->value;
    inorder(root->right);
    if (isOp) cout << ")";
}

int main() {
    string expr = "(2*(a-1)+(3*b))";
    Node* root = buildTree(expr);

    cout << "Inorder traversal (reconstructed expression): ";
    inorder(root);
    cout << endl;

    return 0;
}
