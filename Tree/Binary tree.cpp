#include <iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    
    node(int datas){
        this->data = datas;
        this->left = NULL;
        this->right = NULL;
    }
};

node * buildTree(node *root){
    cout<<"Enter the data"<<endl;
    int d;
    cin>>d;
    root = new node(d);
    if(d == -1){
        return NULL;
    }
    
    cout<<"left node"<<endl;
    root->left = buildTree(root->left);
    cout<<"right node"<<endl;
    root->right = buildTree(root->right);
    return root;
}
// tree is printed using queue where we put each element and then pop that element by putting its left and right nodes

// but to print in tree format we need to insert NULL;
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

void reverseorder(node *root){
queue<node *> q;
stack<node *> stack;
    q.push(root);
    while(!q.empty()){
        node *ans = q.front();
        q.pop();
        stack.push(ans);
             if(ans->left){
             q.push(ans->left);
        }
        if(ans->right){
            q.push(ans->right);
        }

    }
    while(!stack.empty()){
        node* ans = stack.top();
        stack.pop();
        cout<<ans->data<<" ";
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 5 -1 -1 11 -1 -1 6 4 -1 -1 2 -1 -1 
    // level order traversal 
    levelorder(root);
    
    // for reverse level order traversal we gonna use stack 
    cout<<endl<<"reverse level order traversal"<<endl;
    reverseorder(root);
    return 0;
}
