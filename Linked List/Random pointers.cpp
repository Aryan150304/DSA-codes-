// approach 1 of creating a map between original and clone linked list and finding random pointer from original list and connecting to clone linked list 
/*


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

// approach 2 - changing the links and optimising the space complexity to O(n)
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
    void insertattail(Node*& head, Node*& tail, int data) {

        Node* newnode = new Node(data);
        if (head == NULL && tail == NULL) {
            head = newnode;
            tail = newnode;
            return;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        // 1st method is copying the list creating a map
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        temp = head;
        Node* cloneNode = clonehead;
        Node* originalNode = head;
        // create the architecture using 6steps
        while (originalNode != NULL) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            Node* next2 = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next2;
        }
        // assign random nodes using that architecture
        originalNode = head;
        cloneNode = clonehead;
        while (originalNode != NULL) {
            if (originalNode->next != NULL) {
                if (originalNode->random != NULL) {
                    originalNode->next->random = originalNode->random->next;
                } else {
                    originalNode->next->random = NULL;
                }
                originalNode = originalNode->next->next;
            } else {
                originalNode = originalNode->next;
            }
        }
        // de reference the architecture
        originalNode = head;
        cloneNode = clonehead;
        while(originalNode!=NULL&&cloneNode!=NULL){
            originalNode->next = cloneNode->next;
            originalNode = cloneNode->next;
            if(originalNode!=NULL){
                cloneNode->next = originalNode->next;
            }
            else{
                cloneNode->next = NULL;
            }
            cloneNode = cloneNode->next;
        }
        // return the final head;
        return clonehead;
    }
};
