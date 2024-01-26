// best approach 

class Solution {
public:
    ListNode* getMiddle(ListNode*& head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* small = head;
        ListNode* fast = head->next;
        while(small!=NULL&&fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            small = small->next;
        }
        return small;
    }

    ListNode *reverse(ListNode *&head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* small = getMiddle(head);
        // now reverse the list from the middle element
        small->next = reverse(small->next);
  
        small = small->next;
        
        while(small!=NULL){
            if(small->val!=head->val){
                return false;
            }
            small = small->next;
            head = head->next;
        }
        return true;
    }
};
