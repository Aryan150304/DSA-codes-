class binaryiterator {
    // if value true then start from left to right
    // if value false then start from right to left
private:
    stack<TreeNode*> stack;
    bool val;
public:
    binaryiterator(TreeNode* root, bool value) {
        this->val = value;
        pushAll(root);
    }
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        if (val) {
            if (node->right)
                pushAll(node->right);
        } else {
            if (node->left)
                pushAll(node->left);
        }
        return node->val;
    }
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            stack.push(root);
            if (val)
                root = root->left;
            else
                root = root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // one iterator on starting

        // bst must not contain duplicate values
        binaryiterator start(root, true);
        binaryiterator end(root, false);
        int i = start.next();
        int j = end.next();
        while(i<j){
            int value = i+j;
            if(value==k){
                return true;
            }
            if(value<k){
                i = start.next();
            }
            else{
                j = end.next();
            }
        }
        return false;
    }
};
