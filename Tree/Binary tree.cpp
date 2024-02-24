#include <iostream>
#include<queue>
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

// but to print in tree format we need to insertt NULL;
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

// includes creating and level order traversal
int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 5 -1 -1 11 -1 -1 6 4 -1 -1 2 -1 -1 
    // now printing these nodes 
    // level order traversal 
    levelorder(root);
    return 0;
}
