// Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records, complete with a shallow copy implementation? Define attributes such as student name, exam date, and score within the class, and include methods to set these attributes and display exam details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues?

#include <iostream>
#include<cstring>
using namespace std;

class Exam{
    private:
    char *name, *examdate;
    float score;

    public:
    Exam(){
        score = 0.0;
        name = nullptr;
        examdate = nullptr;
    }

    void setName(const char* n){
        if(name!=nullptr) delete[] name;
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }

    void setExamDate(const char* date){
        if(examdate!=nullptr) delete[] examdate;
        examdate = new char[strlen(date)+1];
        strcpy(examdate, date);
    }

    void setScore(float s){score = s; }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Exam Date: " << examdate << endl;
        cout << "Score: " << score << endl;
    }

    ~Exam(){
        delete[] name;
        delete[] examdate;
    }
};

int main(){
    Exam exam1;
    exam1.setName("fatima");
    exam1.setExamDate("25 august");    
    exam1.setScore(95.5);
    cout << "Exam 1 details:" << endl;
    exam1.displayDetails();

    Exam exam2(exam1);
    cout << endl << "over here we created shallow copy of exam 1 , it is stored in exam 2" << endl;
    cout << "exam2 details: " << endl;
    exam2.displayDetails();
    cout << endl << "now change name and date of exam 1: " << endl;
    exam1.setName("syeda fatima waseem");
    exam1.setExamDate("20 november");
    cout << "exam1 details after change: " << endl;
    exam1.displayDetails();
    cout << endl << "exam2 details after changing exam1 details(should be unaffected by change in exam1 but it is shows wrong values/undefined behavior due to shallow copy being created, as the memory exam 2 has been pointing to, gets deleted when exam1 values are reset using setter): " << endl;
    exam2.displayDetails();
}