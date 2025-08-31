// 1. Create a jagged array where each row represents a course and each column represents a student’s marks.
// 2. Input the marks for all students in each course.

// 3. Write a program to:
// • Display the marks of all students course-wise.
// • Find the highest mark in each course.
// • Calculate the average marks of each course.

#include <iostream>
using namespace std;

class Student {
    public:
    string name, id;
    float marks;

    Student(string n, string i, float m) : name(n), id(i), marks(m) {}

    Student() : name(""), id(""), marks(0) {}
};

class System {
    int numOfCourses;
    int *numOfStudents;
    Student **arr;

    public:
    System(int nc, int *ns) : numOfCourses(nc), numOfStudents(ns) {
        cout << "in constructor" << endl;
        arr = new Student*[numOfCourses];
        for (int i = 0; i < numOfCourses; i++) {
            arr[i] = new Student[numOfStudents[i]];
            cout << "yay";
        }
    }

    void enterStudentDetails() {
        for (int i = 0; i < numOfCourses; i++) {
            cout << "Enter details for course " << i + 1 << endl;
            for (int j = 0; j < numOfStudents[i]; j++) {
                string name, id;
                float marks;
                cout << "Enter name, id and marks of student " << j + 1 << ": ";
                cin >> name >> id >> marks;
                arr[i][j] = Student(name, id, marks);
            }
        }
    }

    void dsiplayCourseWiseMarks() {
        for (int i = 0; i < numOfCourses; i++) {
            cout << "Course " << i + 1 << " marks: ";
            for (int j = 0; j < numOfStudents[i]; j++) {
                cout << arr[i][j].marks << " - ";
            }
            cout << endl;
        }
    }

    int highestMarkInEachCourse() {
        for (int i = 0; i < numOfCourses; i++) {
            float highest = -1;
            for (int j = 0; j < numOfStudents[i]; j++) {
                if (arr[i][j].marks > highest) {
                    highest = arr[i][j].marks;
                }
            }
            cout << "Highest mark in course " << i + 1 << " is " << highest << endl;
        }
    }

    int averageMarksInEachCourse() {
        for (int i = 0; i < numOfCourses; i++) {
            float avg, total = 0;
            for (int j = 0; j < numOfStudents[i]; j++) {
                total += arr[i][j].marks;
            }
            avg = total / numOfStudents[i];
            cout << "avg  mark in course " << i + 1 << " is " << avg << endl;
        }
    }

    ~System() {
        for (int i = 0; i < numOfCourses; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    System s(3, new int[3]{2, 3, 4});
    cout << "system created" << endl;
    s.enterStudentDetails();
    s.dsiplayCourseWiseMarks();
    s.highestMarkInEachCourse();
    s.averageMarksInEachCourse();
}