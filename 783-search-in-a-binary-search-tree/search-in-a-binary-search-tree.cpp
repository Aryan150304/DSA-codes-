class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        /// you just need to search for the value so no need to backtrack
        // in BST we dont search whole tree we apply binary searhc and move in O(h)
        while(root!=NULL&&root->val!=val){
            if(root->val>val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return root;
    }
};