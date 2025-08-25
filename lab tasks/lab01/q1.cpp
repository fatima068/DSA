// Q1. Suppose you are developing a bank account management system, and you have defined the BankAccount class with the required constructors. You need to demonstrate the use of these constructors in various scenarios.
// 1. Default Constructor Usage: Create a default-initialized BankAccount object named account1. Print out the balance of account1.
// 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with an initial balance of $1000. Print out the balance of account2.
// 3. Copy Constructor Usage: Using the account2 you created earlier, create a new BankAccount object named account3 using the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the balance of account2 to ensure it hasn't been affected by the transaction involving account3.

#include <iostream>
using namespace std;

class BankAccount {
    float balance;

    public:
    BankAccount(){ balance = 0.0; } // default constructor

    BankAccount(float bal) { balance = bal; } //parameterized constructor

    BankAccount(BankAccount &b1) { balance = b1.balance; } // copy constructor
    
    void print(){ cout << "Balance is " << balance << endl; }

    void deduct(float num) { balance -= num; }
};

int main() {
    BankAccount account1;
    cout << "acc1 balance(create using default constructor): ";
    account1.print();
    BankAccount account2(1000);
    cout << "acc2 balance(create using parameterized constructor): ";
    account2.print();
    BankAccount account3(account2); 
    cout << "acc3 balance(create using copy constructo by copying account 2): ";
    account3.print();
    account3.deduct(200);
    cout << "acc3 balance after deducting $200: ";
    account3.print();
    cout << "acc2 balance after deducting 200 from acc3: ";
    account2.print();
}