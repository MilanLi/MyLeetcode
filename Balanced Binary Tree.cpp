// Balanced Binary Tree

//approach 1

int getHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if(left == -1 || right == -1){
        return -1;
    }
    if(abs(left - right) <= 1){
        return left<right ? right+1 : left+1;
    }
    return -1;
}

bool isBalanced(TreeNode *root) {
    if(getHeight(root) == -1){
        return false;
    }
    return true;
}


//approach 2

int getHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = getHeight(root->left)+1;
    int rightHeight = getHeight(root->right)+1;
    return (leftHeight > rightHeight)? leftHeight : rightHeight;
}

bool isBalanced(TreeNode *root) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(root == NULL){
        return true;
    }
    int diff = getHeight(root->left) - getHeight(root->right);
    if(diff < 2 && diff > -2){
        return isBalanced(root->left) && isBalanced(root->right);
    }
    return false;
}


// we can also use only one function:
// if it is balanced, return height; Otherwise return -1 to indicate the subtree is not balanced.