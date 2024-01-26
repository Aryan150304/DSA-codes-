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
