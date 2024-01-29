// leetcode question - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


class Solution {
public:
    int getLen(ListNode*& head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL; 
            // Edge case: empty list or a list with only one node
        }
        ListNode* temp = head;
        int length = getLen(temp);
        int counter = length - n;
        if(counter==0){
            return head->next;
        }
        
        int i = 0;
        ListNode* prev = NULL;
        temp = head;

        while (i < counter && temp != NULL) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (temp != NULL) {
            prev->next = temp->next;
        }

        temp = head;
        return head;
    }
};
