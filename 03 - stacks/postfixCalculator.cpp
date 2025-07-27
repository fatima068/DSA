#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

// calculates postfix epressions and returns answer, perform 5 basic operations
// +, -, *, /, ^

class Node{
    public:
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {} 
};

class Stack{
    public:
    Node* top;

    Stack() : top(nullptr) {}

    void push(float val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    float pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return -1;
        }
        float retVal = top->data;
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
        // cout << "Popped value" << endl;
        return retVal;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class PostfixCalculator {
    private:
    Stack stack;

    public:
    float calculate(const string& expression) {
        istringstream str(expression);
        string element;
        while (str >> element) {
            // cout << "element: " << element << endl;
            if (element != "+" && element != "-" && element != "*" && element != "/" && element != "^") {
                try {
                    float elementfloat = stof(element);
                    stack.push(elementfloat);
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
            }
            else if (stack.top == nullptr || stack.top->next == nullptr) {
                cout << "Not enough operands for operation: " << element << endl;
                return -1;
            }
            else {
                float numRight = stack.pop();
                float numLeft = stack.pop();
                if (element == "+") {
                    stack.push(numLeft + numRight);
                } 
                else if (element == "-") {
                    stack.push(numLeft - numRight);
                } 
                else if (element == "*") {
                    stack.push(numLeft * numRight);
                } 
                else if (element == "/") {
                    if (numRight == 0) {
                        cout << "Division by zero error" << endl;
                        return -1;
                    }
                    stack.push(numLeft / numRight);
                } else if (element == "^") {
                    stack.push(pow(numLeft, numRight));
                }
            }
        }
        return stack.top->data;
    }
};

int main() {
    PostfixCalculator calculator;
    cout << "Enter a postfix expression: ";
    string expression;
    getline(cin, expression);
    float result = calculator.calculate(expression);
    cout << "Answer: " << result << endl;
}