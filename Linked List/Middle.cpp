// approach 1 
// FLOYD TORTOISE AND HARE ALGO 

Node *middle(Node *head){
    if(head==NULL|| head->next==NULL){
        return head ;
    }
    Node *fast = head;
    Node *slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast= fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head) {
    return middle(head);
}

// Approach 2 - Brute force of finding the length of linked list and then traversing till half of the length and returning the middle element


int getlength(Node *head){
    int length =0;
    Node *temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

Node *findMiddle(Node *head) {
    int length = getlength(head);
    int mid =(length/2) ;
    while(mid--){
        head = head->next;
    }
    return head;
}
