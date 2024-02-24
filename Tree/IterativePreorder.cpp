
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // if we try to solve using auxiliary stack space 
        stack<TreeNode*> stack;
        vector<int> preorder;
        TreeNode* node = root;
        while(true){
            if(node!=nullptr){
                stack.push(node);
                preorder.push_back(node->val);
                node = node->left;
            }
            else{
                if(stack.empty()){
                    break;
                }
                // now move to right 
                node = stack.top();
                stack.pop();
                node = node->right;
            }
        }
        return preorder;
    }
};
