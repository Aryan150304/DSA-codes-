// Q1 - to create a linked list with unique elements 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        // list has 2 items
        // iterate the list till 2nd last element 
        ListNode* curr = head;
        while(curr->next!=NULL){
            if(curr->val==curr->next->val){
                ListNode* forward= curr->next->next;
                ListNode* todelete = curr->next;
                delete todelete;
                curr->next = forward;
            }  
            else {
                curr = curr->next;
            }
        }
        return head;
    
        
    }
};
