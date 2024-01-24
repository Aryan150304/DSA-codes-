// leetcode medium problem link - https://leetcode.com/problems/linked-list-cycle-ii/submissions/1155877644/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head ==NULL||head->next==NULL){
            return NULL;
        }
        int count =0;
        ListNode *small = head;
        ListNode *fast = head;
        while(small!=NULL&&fast!=NULL&&fast->next!=NULL){
            small = small->next;
            fast= fast->next->next;
            if(small==fast){
                break;
            }
        }
        if(small==fast){
            small= head;
            while(small!=fast){
                small = small->next;
                fast= fast->next;
            }
            return small;
        }
        return NULL;
        
    }
};
