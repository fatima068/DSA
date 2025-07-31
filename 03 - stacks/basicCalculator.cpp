#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

// calculates postfix epressions and returns answer, perform 5 basic operations
// +, -, *, /, ^

class strNode {
    public:
    string data;
    strNode* next;

    strNode(string val) : data(val), next(nullptr) {} 
};

class Node{
    public:
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {} 
};

class CharStack{
    public:
    strNode* top;

    CharStack() : top(nullptr) {}

    void push(string val) {
        strNode* newNode = new strNode(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "CharStack is empty, cannot pop" << endl;
            return " ";
        }
        string retVal = top->data;
        strNode* toDelete = top;
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

    ~CharStack() {
        while (!isEmpty()) {
            pop();
        }
    }
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
    CharStack charStack;

        float postfixCalculator(const string& postfixExpression) {
        istringstream str(postfixExpression);
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

    // read the infix exp left to right
    // if it is a operand, append to postfix
    // if left bracket, push to stack
    // if right bracket, pop everything from stack until left bracket found & append everything to postfix except left bracket
    // if operator, check the operator on top of stack
    // if stack wale ki precedence is zyada or equal, pop it from stack and append to postfix, check precedence again and when stack top ki precedence is lesser, push the operator u have to the stack
    // else if stack top ki precedence is kam, push your operator to stack
    // when end of infix reached, pop everything from stack and append to postfix
    string toPostfix(const string& infixExpression) {
        string postfix = "";
        istringstream str(infixExpression);
        string characterToCheck;
        while (str >> characterToCheck) {
            if (characterToCheck == "(") {
                charStack.push(characterToCheck);
            }

            else if (characterToCheck == "+") {
                while (!charStack.isEmpty() && (charStack.top->data == "*" || charStack.top->data == "^" || charStack.top->data == "/" || charStack.top->data == "-" || charStack.top->data == "+")) {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                charStack.push(characterToCheck);
            }

            else if (characterToCheck == "-") {
                while (!charStack.isEmpty() && (charStack.top->data == "*" || charStack.top->data == "^" || charStack.top->data == "/" || charStack.top->data == "+" || charStack.top->data == "-")) {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                charStack.push(characterToCheck);
            }

            else if (characterToCheck == "*") {   
                while (!charStack.isEmpty() && (charStack.top->data == "/" || charStack.top->data == "^" || charStack.top->data == "*")) {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                charStack.push(characterToCheck);
            }

            else if (characterToCheck == "/") {
                while (!charStack.isEmpty() && (charStack.top->data == "*" || charStack.top->data == "^" || charStack.top->data == "/")) {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                charStack.push(characterToCheck); 
            }

            else if (characterToCheck == "^") {
                while (charStack.top->data == "^") {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                charStack.push(characterToCheck);
            }

            else if (characterToCheck == ")") {
                while (charStack.top->data != "(") {
                    postfix += charStack.pop();
                    postfix += " ";
                }
                // pop the right bracket here
                charStack.pop();
            }

            else { // assume it is a number and append to postfix
                postfix += characterToCheck;
                postfix += " "; // har number ke baad ek space hona chahiye
                }
            
        }
        // infix poora read karliya, now pop everything that remains in stack and append to postfix
        while(charStack.isEmpty() == false) {
            postfix += charStack.pop();
            postfix += " ";
        }
        return postfix;
    }

    public:
    float calculate(const string& infixInput) {
        string postfix = toPostfix(infixInput);
        cout << "postfix is: " << postfix << endl;
        float ans = postfixCalculator(postfix);
        cout << "answer: " << ans << endl;
        return ans;
    }
};

int main() {
    PostfixCalculator calculator;
    cout << "Enter mathematical expression(spearated by spaces): ";
    string expression;
    getline(cin, expression);
    calculator.calculate(expression);
}