/*
In case of finding middle always start fast = head->next to consider even nodes case 
but in some cases like detecting cycle it may fail so in that case start from fast = head 
*/

class Solution {
public:
    ListNode* getMiddle(ListNode*& head) {
        ListNode* small = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            small = small->next;
        }
        return small;
    }
    ListNode* merge(ListNode*& left, ListNode*& right) {
        ListNode* lefthead = left;
        ListNode* rigthhead = right;
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if (left != NULL) {
            temp->next = left;
        }
        if (right != NULL) {
            temp->next = right;
        }

        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
