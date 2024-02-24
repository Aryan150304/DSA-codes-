
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        // this can be done on 2 stacks 
        // we pop the top element of stack 1 
        // push it into stack 2
        // now we push left and right elemnt of top element of stack 2 into stack 1 
        // and repeat the same opperation until stack 1 is empty 

        // then we pop the stack 2 and save it an array and return that array 
        stack<TreeNode*> st1,st2;
        TreeNode* node = root;
        vector<int> postorder;
        st1.push(node);
        while(!st1.empty()){
            TreeNode *temp = st1.top();
            st1.pop();
            st2.push(temp);

            if(temp->left!=NULL){
                st1.push(temp->left);
            }

             if(temp->right!=NULL){
                st1.push(temp->right);
            }
        }


        while(!st2.empty()){
            TreeNode *temp = st2.top();
            st2.pop();
            postorder.push_back(temp->val);
        }
        
        return postorder;
    }
};
