// Design a program that maintains library book records using dynamic arrays.
// => Each row represents a category (e.g., Fiction, Science, History).
// => Each category has a different number of books (use a jagged array).
// => Store book IDs dynamically and allow the user to search for a given book ID.
// => Print whether the book is available and in which category.

#include <iostream>
using namespace std;

int main(){
    int numcategory;
    int *numInEachCategory;
    string *categoryArray;
    string **bookIDs;

    cout << "how many number of categories? ";
    cin >> numcategory;
    categoryArray = new string[numcategory];
    numInEachCategory = new int[numcategory];

    for (int i = 0; i < numcategory; i++){
        cout << "name of category " << i + 1 << "? ";
        cin >> categoryArray[i];
        cout << "how many books in " << categoryArray[i] << "? ";
        cin >> numInEachCategory[i];
    }

    bookIDs = new string*[numcategory];
    for(int i=0; i < numcategory; i++) {
        bookIDs[i] = new string[numInEachCategory[i]];
        for (int j = 0; j < numInEachCategory[i]; j++){
            cout << "book ID " << j + 1 << " in " << categoryArray[i] << "? ";
            cin >> bookIDs[i][j];
        }
    }

    string idToSearch; bool found = false;
    cout << "which book ID do you want to search? ";
    cin >> idToSearch;
    for (int i=0; i<numcategory; i++){
        for(int j=0; j<numInEachCategory[i]; j++) {
            if (bookIDs[i][j] == idToSearch) {
                cout<< idToSearch << " is available in category " << categoryArray[i] << endl;
                found = true;
            }
        }
    }
    if (found == false) {
        cout << idToSearch << " is not available " << endl;
    }
    delete[] categoryArray;
    delete[] numInEachCategory;
    for(int i=0; i < numcategory; i++) {
        delete[] bookIDs[i];
    }
    delete[] bookIDs;
}