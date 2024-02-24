#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    
    node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};


node *buildlevel(node *root){
    queue<node *> q;
    cout<<"Enter data for the node"<<endl;
    int d;
    cin>>d;
    root = new node(d);
    q.push(root);
    while(!q.empty()){
        node* ans = q.front();
        q.pop();
        cout<<"Enter the data for left node of "<<ans->data<<endl;
        int leftNode;
        cin>>leftNode;
        if(leftNode!=-1){
            ans->left = new node(leftNode);
            q.push(ans->left);
        }
        
        cout<<"Enter the data for right node of "<<ans->data<<endl;
        int rightNode;
        cin>>rightNode;
        if(rightNode!=-1){
            ans->right = new node(rightNode);
            q.push(ans->right);
        }
    }
    return root;
}

void levelorder(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *ans = q.front();
        q.pop();
        if(ans==NULL){
            cout<<endl;
           if(!q.empty()){
               q.push(NULL);
           }
        }
        else{
             cout<<ans->data<<" ";
             if(ans->left){
             q.push(ans->left);
        }
        if(ans->right){
            q.push(ans->right);
        }
        }
    }
}

int main()
{
    // dfs 1 3 6 5 4 2 -1 -1 -1 -1 -1 -1 -1
    node *root;
    // root = buildTree(root);
    // levelorder(root);
    
    // now building from level order
    root = buildlevel(root);
    levelorder(root);
    
    return 0;
}
