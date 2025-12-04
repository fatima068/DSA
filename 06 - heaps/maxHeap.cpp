#include <iostream>
using namespace std; 

class MaxHeap{
    public:
    int arr[100];
    int size;

    MaxHeap():size(0) {}

    void insert(int val){
        if(size ==100) {
            cout <<"heap overflow"<< endl;
            return;
        }
        arr[size] = val;
        heapifyUp(size);
        size++;
        cout << "inserted " << val <<endl;
    }

    void heapifyUp(int index){
        while(index !=0 && arr[index] > arr[parent(index)]) {
            int temp = arr[index];
            arr[index] = arr[parent(index)];
            arr[parent(index)] = temp;

            index = parent(index);
        }
    }

    void display() {
        for(int i =0; i<size; i++) {
            cout << arr[i] << "  ";
        }
        cout <<endl;
    }

    void deleteRoot() {
        if(size ==0) {
            cout <<"heap underflow" <<endl;
            return;
        }
        cout<<"deleting element " <<arr[0]<<endl;

        arr[0] =arr[size-1];
        size--;
        heapifyDown(0);
    }

    void heapifyDown(int index) {
        int largest =index;
        int l=leftChild(index);
        int r= rightChild(index);

        if(l< size &&arr[l]>arr[largest])  largest =l;
        if(r< size &&arr[r]>arr[largest])  largest =r;
        if(largest!= index) {
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest]= temp;
            heapifyDown(largest);
        }
    }

    void heapSort() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        for (int i = (size/2)-1; i>=0; i--) {
            int root = i;
            while (true) {
                int largest = root;
                int left = 2*root + 1;
                int right = 2*root + 2;
                
                if (left < size && arr[left] > arr[largest])
                    largest = left;
                if (right < size && arr[right] > arr[largest])
                    largest = right;
                    
                if (largest == root) break;
                
                swap(arr[root], arr[largest]);
                root = largest;
            }
        }
        
        for (int i = size-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            
            int root = 0;
            while (true) {
                int largest = root;
                int left = 2*root + 1;
                int right = 2*root + 2;
                
                if (left < i && arr[left] > arr[largest])
                    largest = left;
                if (right < i && arr[right] > arr[largest])
                    largest = right;
                    
                if (largest == root) break;
                
                swap(arr[root], arr[largest]);
                root = largest;
            }
        }
        
        cout << "Heap sort completed!" << endl;
    }

    void update_key(int i,int newVal) {
        if (i<0 || i>=size) {
            cout << "invalid" << endl;
            return;
        }
        
        int oldVal=arr[i];
        arr[i]=newVal;
        
        if (newVal >oldVal) {
            heapifyUp(i);
        } else if (newVal<oldVal) {
            heapifyDown(i);
        }
        cout <<"updated index " <<i<< " from "<<oldVal << " to " <<newVal<< endl;
    }

    int parent(int i) {return (i-1) / 2; }
    int leftChild(int i){ return (2*i)+ 1; }
    int rightChild(int i){ return (2 * i) + 2; } 
};

int main (){
    MaxHeap heap;
    heap.insert(8);
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(4);
    
    cout << "Original heap: ";
    heap.display();
    
    heap.update_key(3, 9); 
    cout << "Heap after updating index 3 to 9: ";
    heap.display();
    
    heap.update_key(1, 3); 
    cout << "After updating index 1 to 3: ";
    heap.display();
    
    heap.deleteRoot();
    cout << "After deleting root: ";
    heap.display();

    cout << "\n--- Member Function Heap Sort ---" << endl;
    heap.heapSort();
    cout << "Heap after sorting: ";
    heap.display();
}