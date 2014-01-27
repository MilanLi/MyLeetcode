// Flatten Binary Tree to Linked List

//leverage the pre-order traversal


TreeNode* preorder(TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        return root;
    }
    
    if(root->left == NULL){
        return preorder(root->right);
    }
    TreeNode* temp;
    if(root->right == NULL){
        temp = preorder(root->left);
        root->right = root->left;
        root->left = NULL;
        return temp;
    }
    temp = root->right;
    preorder(root->left)->right = temp;
    root->right = root->left;
    root->left = NULL;
    return preorder(temp);
}

void flatten(TreeNode *root) {
    if(root != NULL){
        preorder(root);    
    }
}