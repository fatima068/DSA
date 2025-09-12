 #include <iostream>
using namespace std;

class  Node {
   public:
   Node *next;
   int val;
   Node ( int v ): val (v), next (nullptr ) { }
};

class LinkedList{
 public:
   Node* head;
   Node* tail;

   LinkedList() : head ( NULL) , tail (NULL) { }

   void pushBack ( int v ){   
        Node * newnode = new Node(v);   
        if(tail ==NULL){
             head=newnode;
             tail =newnode;
             return;
        }
        tail->next = newnode;
        tail = newnode;
   }

   Node* reverseKGroup (Node* head,int k){
        if (!head ||k <= 1) 
        return head;
        Node* newhead =nullptr;    
        Node* newtail=nullptr;

        Node* curent = head;

        while (curent){
             Node *check=curent;
             int count=0;
             while (check && count<k){
                  check = check->next;
                  count ++; 
             }

             if (count<k){
                  while (curent) {
                      Node * node = new Node( curent->val);
                      if (!newhead) {
                           newhead =node;
                           newtail =node;  
                      } else 
                      {
                           newtail->next = node;
                           newtail = node;
                      }
                      curent = curent->next;
                  }
                  break;
             }
             Node *arr[100];
             Node * temp=curent;
             for ( int i=0; i<k;i++ ) {
                  arr [i] = temp;  
                  temp = temp->next;
             }

             for ( int i = k-1; i >=0; i-- ){
                  Node * node = new Node(arr[i]->val );
                  if (!newhead){
                       newhead = node;
                       newtail = node;
                  } else {
                       newtail -> next = node;
                       newtail = node;
                  }
             }

             curent = temp;
        }  
        return newhead;
   }

    void print(Node* head = nullptr) {
        Node* temp;
        if(head == nullptr)
             temp = this->head;
        else
            temp=head;
        while(temp!= nullptr) {
            cout <<temp->val << " ";
            temp=temp->next;
        }
        cout << endl;
    }

    ~LinkedList(){
        Node* current = head;
        while (current!= nullptr) {
            Node* nextNode =current->next;
            delete current;
            current =nextNode;
        }
        delete current;
        delete head;
        delete tail;
    }
};


int main() {
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(7);
    int k = 3;
    list.print();
    Node* result = list.reverseKGroup(list.head, k);
    cout << " groups of " << k << ": ";
    list.print(result);
     delete result;
    
}