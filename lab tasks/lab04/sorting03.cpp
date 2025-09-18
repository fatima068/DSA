
// 3.   You are asked to sort a list of product prices for a retail store using Comb Sort. However, 
// instead of using the standard shrink factor of 1.3 (as typically used in Comb Sort), you must 
// create and implement a custom shrink factor of your choice that you think can align with the 
// problem.
#include <iostream>
using namespace std;
void combSortCustom(int arr[],int n) {
    float shrinkFactor=1.25; // insteead of 1.3 we take 1.25 to make it more effeicient by reducing gap faster
    int gap= n;
    bool swapped= true;
    while (gap >1||swapped) {
        gap =int(gap/shrinkFactor);
        if (gap<1) 
            gap= 1;
        swapped = false;
        for (int i=0; i+gap<n; i++) {
            if (arr[i] >arr[i+gap]) {
                swap(arr[i], arr[i +gap]);
                swapped=true;
            }
        }
    }
}
int main(){
    int prices[]={250, 100, 300, 150, 200, 350, 400};
    int n=7;
    cout << "unsorted: ";
    for (int i=0; i<n;i++) 
        cout <<prices[i]<< " ";
    cout<<endl;
    combSortCustom(prices, n);
    cout<< "sorted: ";
    for (int i =0;i<n; i++) cout<< prices[i] << " ";
}



