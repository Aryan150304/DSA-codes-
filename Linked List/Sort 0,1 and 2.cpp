// approach 1
/*
Count the number of 0 ,1, and 2 and then replace the data with 0's and 1's and 2's
*/


Node* sortList(Node *head){
    // Write your code here.
    int count0 =0;
    int count1 =0;
    int count2 =0;
    Node*curr = head;
    while(curr!=NULL){
        if(curr->data==0){
            count0++;
        }
        else if(curr->data==1){
            count1++;
        }
        else{
            count2++;
        }
        curr = curr->next;
    }
    
    curr = head;
    while(curr!=NULL){
        if(count0!=0){
            curr->data = 0;
            count0--;
        }
        else if(count1!=0){
            curr->data = 1;
            count1--;
        }
        else{
            curr->data = 2;
            count2--;
        }
        curr = curr->next;
    }
    return head;
}

/* 
Another approach if the data replacement is not allowed. In that case make separate linked list for one two and zero and at the end 
merge them by considering some extreme test cases
*/
void insert(Node*&head, int data){
    Node *newNode = new Node(data);
    head->next = newNode;
    head = newNode;
}
Node* sortList(Node *head){
    // Write your code here
    if((head==NULL||head->next==NULL)){
        return head;
    }

    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;


    Node *curr = head;
    while(curr!=NULL){
        if(curr->data==0){
            insert(zerotail,0);
        }
        else if(curr->data==1){
            insert(onetail,1);
        }
        else{
            insert(twotail,2);
        }
        curr = curr->next;
    }

    // now merge the all lists
    if(onehead->next!=NULL){
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else{
        zerotail->next = twohead->next;
    }

   
    twotail->next = NULL;
    head = zerohead->next;
    delete onehead;
    delete zerohead;
    delete twohead;
    return head;
}
