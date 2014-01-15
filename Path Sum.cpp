// Path Sum

//be careful: 1. the value may not be positive; 2. the path must be from root to leaf;
bool hasPathSum(TreeNode *root, int sum) {
    if(root == NULL){
        return false;
    }
    if(root->val == sum && root->left == NULL && root->right == NULL){
        return true;
    }
    else{
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
}