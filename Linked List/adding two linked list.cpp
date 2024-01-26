class Solution {
public:
void addinlist(ListNode* &head, ListNode* &tail, int sum){
    ListNode *newnode = new ListNode(sum);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return ;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL;
        ListNode * tail = NULL;
        int carry =0;
        int sum =0;
        while(l1!=NULL||l2!=NULL||carry!=0){
            int val1 =0;
            int val2=0;
            if(l1!=NULL){
                val1 = l1->val;
                l1= l1->next;
            }
            if (l2!=NULL){
                val2 = l2->val;
                l2 =l2->next;
            }
            sum = carry + val1 + val2;
            carry = sum/10;
            sum = sum%10;
            addinlist(head,tail,sum);
        }
        return head;

    }
};
