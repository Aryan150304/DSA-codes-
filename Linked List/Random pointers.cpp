// approach 1 of creating a map between original and clone linked list and finding random pointer from original list and connecting to clone linked list 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertattail(Node*&head, Node*&tail, int data){
        Node *newnode = new Node(data);
        if(head==NULL&&tail==NULL){
            head = newnode;
            tail = newnode;
            return ;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        // creating a clone list with only next pointer 
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        Node *temp = head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }

        // created a clone now we need to create a map
        unordered_map<Node*,Node*> mapping;
        temp = head;
        Node *temp2 = clonehead;
        while(temp!=NULL){
            mapping[temp]= clonehead;
            temp = temp->next;
            clonehead = clonehead->next;
        }
        clonehead = temp2;
        temp = head;

        // now we have created a map now we traverse the normal linked list only and get the mapped random node and just connect the cloned node 
        while(temp!=NULL){
            Node *random = mapping[temp->random];
            clonehead->random = random;
            clonehead= clonehead->next;
            temp = temp->next;
        }
        return temp2;
        
    }
};
