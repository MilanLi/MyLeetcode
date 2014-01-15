// Symmetric Tree


bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode){
    if(leftNode == NULL && rightNode == NULL){
        return true;
    }
    if(leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val){
        return false;
    }
    return isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode *root) {
    if(root == NULL){
        return true;
    }
    return isSymmetric(root->left, root->right);
}