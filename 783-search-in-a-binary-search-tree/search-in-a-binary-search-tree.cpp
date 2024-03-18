class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       if(root==NULL){
        return NULL;
       }
       if(root->val==val){
        return root;
       }
       TreeNode* lh = searchBST(root->left,val);
       if(lh) return lh;
       TreeNode* rh = searchBST(root->right,val);
       return rh;
    }
};