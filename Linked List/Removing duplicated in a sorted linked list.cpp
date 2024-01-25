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

// follow up - to create a linked list which only contains element that comes once. If the element comes more than once is not included

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* forw = curr->next;
        bool issame = false;
        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                ListNode* forward = curr->next->next;
                ListNode* todelete = curr->next;
                delete todelete;
                curr->next = forward;
                issame = true;
            } else if (issame == true) {
                prev->next = curr->next;
                ListNode* tobedeleted = curr;
                curr = curr->next;
                delete tobedeleted;
                issame = false;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if (issame == true) {
            prev->next = curr->next;
            ListNode* tobedeleted = curr;
                curr = curr->next;
                delete tobedeleted;
        }

        // delete dummy;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
