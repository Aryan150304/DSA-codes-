// approach is that store the next element and direct the current element to prev element and then move to next element 
// using iteration 

 if(head == NULL||head->next==NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            ListNode* forward  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;

// same approach using recursion

void reverse(ListNode*& head, ListNode* curr, ListNode* prev) {
        if (curr == NULL) {
            head = prev;
            return ;
        }
        reverse(head, curr->next, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        // solving through the iterative approach
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head, curr, prev);
        return head;
    }
