class Solution {
public:
    ListNode* solve(ListNode* first, ListNode* second) {
        // // we will consider extreme test cases at the end
        ListNode* head = first;
        ListNode* curr1 = first->next;
        ListNode* prev = first;
        ListNode* curr2 = second;

        while (curr1 != NULL && curr2 != NULL) {
            ListNode* forward = curr2->next;
            if (curr2->val <= curr1->val && curr2->val >= prev->val) {
                prev->next = curr2;
                prev = curr2;
                curr2->next = curr1;
                curr2 = forward;
            } else {
                prev = curr1;
                curr1 = curr1->next;
            }
        }
        if(prev->next==NULL&&curr2!=NULL){
            prev->next = curr2;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {

        if (first == NULL) {
            return second;
        }
        if (second == NULL) {
            return first;
        }

        if (first->val >= second->val) {
            return solve(second, first);
        } else {
            return solve(first, second);
        }
    }
};
