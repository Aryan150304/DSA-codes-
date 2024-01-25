// approach 1 is to use a map 
#include <bits/stdc++.h> 

Node *removeDuplicates(Node *head)
{
    if(head==NULL||head->next ==NULL){
        return head;
    }
    // Write your code here
    map<int, int> mp;
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        if(mp[curr->data]==0){
            cout<<curr->data<<" ";
            mp[curr->data]++;
            prev = curr;
            curr = curr->next;
        }
        else{
            Node *tbd = curr;
            prev->next =curr->next;
            curr=curr->next;
            delete tbd;
        }
    }
    return head;
}

// approach 2 is to for every element in the linked list search for the another same elements and delete them

#include <bits/stdc++.h> 

Node *removeDuplicates(Node *head)
{
    if(head==NULL||head->next ==NULL){
        return head;
    }
    // Write your code here
    map<int, int> mp;
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        if(mp[curr->data]==0){
            cout<<curr->data<<" ";
            mp[curr->data]++;
            prev = curr;
            curr = curr->next;
        }
        else{
            Node *tbd = curr;
            prev->next =curr->next;
            curr=curr->next;
            delete tbd;
        }
    }
    return head;
}
