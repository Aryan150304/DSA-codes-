
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return{};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flat = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> store(size);
            int i = 0;
            while (i<size) {
                int index = i;
                TreeNode* node = q.front();
                q.pop();
                if(flat==1){
                    index = size -1-i;
                }
                if (node != nullptr) {
                    store[index] = node->val;
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
                i++;
            }
            flat = !flat;
            ans.push_back(store);
        }
        return ans;
    }
};
