class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
      // as it is a BST 
    //   so we need to compare the value 
    if(root==NULL){
        return  NULL;
    }
    if(root->val==val){
        return root ;
    }
    if(root->val>val){
        TreeNode *lh = searchBST(root->left,val);
        if(lh )return lh;
    }
        return searchBST(root->right,val);
    }
};