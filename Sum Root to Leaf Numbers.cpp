// Sum Root to Leaf Numbers


void sumNumbers(TreeNode* root, int& ret, int sum = 0){
    if(root != NULL){
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            ret += sum;
        }
        else{
            sumNumbers(root->left, ret, 10*sum);
            sumNumbers(root->right, ret, 10*sum);
        }
    }
}

int sumNumbers(TreeNode *root) {
    int ret = 0;
    sumNumbers(root, ret);
    return ret;
}