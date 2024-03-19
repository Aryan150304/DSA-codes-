class Solution {
public:
    void solve(TreeNode* root, int k, int& counter, int&ans) {
        if(root==nullptr){
            return ;
        }
        solve(root->left,k,counter,ans);
        counter++;
        if(counter==k){
            ans = root->val;
            return ;
        }
        solve(root->right,k,counter,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int counter = 0;
        solve(root, k, counter,ans);
        return ans;
    }
};