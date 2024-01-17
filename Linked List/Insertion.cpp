#include<iostream> 
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
    }
};

void insertathead(Node *&head, int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printNode(Node *&head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
    temp = temp->next;
    }
    cout<<endl;
    
}
void insertatlast(Node *&tail, int data){
    Node *newNode = new Node(data);
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void insertatmiddle(Node*&tail,Node*&head, int data, int position){
    if(position==1){
        insertathead(head,data);
        return ;
    }
    Node *temp = head;
    
    for(int i =1;i<position-1;i++){
        temp = temp->next;
    }
    if(temp->next==NULL){
        insertatlast(tail,data);
        return ;
    }
    
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

int main(){
    Node *newNode = new Node(10);
    
    Node *head = newNode;
    Node *tail = newNode;
    insertathead(head,20);
    insertathead(head,30);
    printNode(head);
    // output - 30 20 10 
    insertatlast(tail,50);
    insertatlast(tail,40);
    printNode(head);
     // 30 20 10 50 40
     
    insertatmiddle(tail,head,1,1); // actually middle  1 30 20 10 50 40
     printNode(head);
    insertatmiddle(tail,head,300,4) ;// first pe insert 1 30 20 300 10 50 40
     printNode(head);
    insertatmiddle(tail,head ,500,8) ;// last pe insert 1 30 20 300 10 50 40 500
     printNode(head);
     cout<<tail->data<<endl;
}
