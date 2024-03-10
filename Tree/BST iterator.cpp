// it uses iterative inorder approach in a binary search tree 
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
class BSTIterator {
    private: stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        // in order to use O(h) memory we need to use iterative approach
        pushAll(root);
    }
    
    int next() {
        TreeNode *node = stack.top();
        stack.pop();
        if(node->right){
            pushAll(node->right);
        } 
        return node->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
    void pushAll(TreeNode*root){
        // push all left element;
        while(root!=NULL){
            stack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
