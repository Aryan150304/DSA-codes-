// used 2 approach 


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        // find the height of the treee using recursion and DFS approach
        if (root == nullptr) {
            return 0;
        }
        int heightone = maxDepth(root->left);
        int heighttwo = maxDepth(root->right);
        return max(heightone, heighttwo) + 1;


        // usign level order traversal 

        // USING BFS APPROACH
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
