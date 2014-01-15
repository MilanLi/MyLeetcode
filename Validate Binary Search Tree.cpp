// Validate Binary Search Tree


bool isValidBST(TreeNode* root, int minVal, int maxVal){
    if(root == NULL){
        return true;
    }
    if(root->val < maxVal && root->val > minVal){
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
    else{
        return false;
    }
}

bool isValidBST(TreeNode *root) {
    return isValidBST(root, INT_MIN, INT_MAX);
}