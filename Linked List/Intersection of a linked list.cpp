// 1 st approach using hashmap but has high space complexity 

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, int> map;
        ListNode *temp = headA;
        while(temp!=NULL){
            map[temp]++;
            temp = temp->next;
        }
        ListNode *temp2 = headB;
        while(temp2!=NULL){
            if(map[temp2]>0){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};
// 2nd approach by calculating length of both linked list and traversing the larger LL to make both equal 

class Solution {
public:
    int getlen(ListNode*& head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        // first find length of both
        // now traverse the longer linked list to that part
        int len1 = getlen(temp1);
        int len2 = getlen(temp2);
        temp1 = headA;
        temp2 = headB;
        int dif;
        ListNode* traverse;
        if (len1 > len2) {
            dif = len1 - len2;
            int i = 0;
            while (i++ < dif && temp1 != NULL) {
                temp1 = temp1->next;
            }
        } else {
            dif = len2 - len1;
            int i = 0;
            while (i++ < dif && temp2 != NULL) {
                temp2 = temp2->next;
            }
        }

        // now both list are of equal length
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
