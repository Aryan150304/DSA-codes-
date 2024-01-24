// reversing k nodes 

/* The approach is to first reverse k nodes and then age recursion smbhal lega. Before every reversal check if the node length==k if yes
then reverse and return the head of reversed node else return the head of non reversed node*/

// link - https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1155615296/

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
    bool getlen(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (count < k - 1) {
            curr = curr->next;
            if (curr == NULL) {
                return false;
            }
            count++;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // now reverse linked list for this k group
        int count = 0;
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        bool length = getlen(head, k);
        if (length != true) {
            return head;
        }

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // now we have reversed so ab to recursion sambhal lega all we have to
        // make a connection
        if (curr != NULL) {
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};
