// A company has multiple departments, each department has a different number of employees.
// => Use a jagged array where each row corresponds to a department and columns store employee salaries.
// Calculate:
// -> The highest salary in each department.
// -> The department with the overall maximum average salary.

#include <iostream>
using namespace std;    

int main(){
    int **arr;
    int numdept;
    int *employeeInEachDept;
    cout << "how many number of departments? ";
    cin >> numdept;
    employeeInEachDept = new int[numdept];
    arr = new int*[numdept];

    for (int i = 0; i < numdept; i++){
        cout << "num of employees in department " << i + 1 << "? ";
        cin >> employeeInEachDept[i];
        arr[i] = new int[employeeInEachDept[i]];
    }

    for (int i = 0; i < numdept; i++){
        for (int j = 0; j < employeeInEachDept[i]; j++){
            cout << "what is salary of employee " << j + 1 << " in department " << i + 1 << "? ";
            cin >> arr[i][j];
        }
    }
    int highestSalary;
    for (int i = 0; i < numdept; i++){
        highestSalary = 0;
        for (int j = 0; j < employeeInEachDept[i]; j++){
            if (arr[i][j] > highestSalary){
                highestSalary = arr[i][j];
            }
        }
        cout << "highest salary in department " << i + 1 << ": " << highestSalary << endl;
    }
    int highestAvg = 0, deptnum;
    for (int i=0; i < numdept; i++){
        int total = 0;
        for (int j = 0; j < employeeInEachDept[i]; j++){
            total += arr[i][j];
        }
        int avg = total / employeeInEachDept[i];
        if (avg > highestAvg){
            highestAvg = avg;
            deptnum = i + 1;
        }
    }
    cout << "department " << deptnum << " has the highest average salary: " << highestAvg << endl;
    delete[] employeeInEachDept;
    for (int i = 0; i < numdept; i++){
        delete[] arr[i];
    }
    delete[] arr;
}