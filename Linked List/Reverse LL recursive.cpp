// one recursive approach was discussed in iterative file another approach is here
// in that approach we were moving to next element and directing it to prev element and then at last storing the head 

// in this approach we will store the final head and return the final head and rather than connecting it with prev we will connect with upcoming element 
// so this approach is reverse of the previous recursive approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode*& head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newesthead = reverse(head->next);
        head->next->next = head ;
        head->next = NULL;
        return newesthead;
    }

    ListNode* reverseList(ListNode* head) {
        // solving through the recursive approach
        if (head == NULL || head->next == NULL) {
            return head;
        }
        head = reverse(head);
        return head;
    }
};
