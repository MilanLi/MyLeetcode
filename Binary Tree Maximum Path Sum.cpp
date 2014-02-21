// Binary Tree Maximum Path Sum


//return the max value that can be cannected. 
//For those cannot connect, simply compare them with Max

int PathSum(TreeNode* curr, int& Max){
    if(curr == NULL){
        return 0;
    }
    int left = PathSum(curr->left, Max);
    int right = PathSum(curr->right, Max);
    int l = max(left, 0);
    int r = max(right, 0);
    Max = max(Max, l + r + curr->val);
    return curr->val + max(l, r);
}

int maxPathSum(TreeNode *root) {
    int Max = INT_MIN;
    PathSum(root, Max);
    return Max;
}