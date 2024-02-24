/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        // iterative approach
        // we create a stack same like recursion 
        vector<int> inorder;
        stack<TreeNode*> stack;
        TreeNode* node = root;

        while(true){
           if(node!=nullptr){
               stack.push(node);
               node = node->left;
           } 
           else{
               if(stack.empty()){
                   break;
               }
               node = stack.top();
               stack.pop();
               // moving to node
               inorder.push_back(node->val);
               // moving to right most element
               node = node->right;

           }
        }
        return inorder;
    }
};
