
void changeTree(BinaryTreeNode<int>* root) {
    // Write your code here.
    // everytime u go down u make children big and everytime when u come back
    // u make root == child
    if (root == NULL) {
        return;
    }
    int val = root->data;
    int sum = 0;
    if (root->left) {
        sum += root->left->data;
    }
    if (root->right) {
        sum += root->right->data;
    }
    if (val > sum) {
        if (root->left) {
            root->left->data = val;
        }
        if (root->right) {
            root->right->data = val;
        }
    } else {
        root->data = sum;
    }
    changeTree(root->left);
    changeTree(root->right);
    sum =0;
    if (root->left) {
        sum += root->left->data;
    }
    if (root->right) {
        sum += root->right->data;
    }
    if (sum != 0) {
        root->data = sum;
    }
    return;
}
