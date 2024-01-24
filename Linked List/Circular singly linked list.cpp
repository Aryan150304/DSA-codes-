
#include <iostream>

using namespace std;
// implementing CLL
class Node {
    public: 
    int data;
    Node *next;
    
    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node*&tail, int data, int elem =0){
    Node *newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        newNode->next = newNode;
        return ;
    }
    
    Node *curr = tail;
    while(curr->data!=elem){
        curr= curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void print(Node*&tail){
    if(tail==NULL){
        cout<<"LIST IS EMPTY"<<endl;
        return ;
    }
    Node *curr = tail;
   do {
        cout<<curr->data<<" ";
        curr = curr->next;
    } while(curr != tail);
    cout<<endl;
}

int main()
{
    Node *tail = NULL;
    insert(tail,10);
    print(tail);
    // 10
    insert(tail,20,10);
    print(tail);
    // 10 20 
    insert(tail,30,10);
    print(tail);
    // 10 30 20
    return 0;
}
