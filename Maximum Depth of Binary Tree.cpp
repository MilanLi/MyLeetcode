// Maximum Depth of Binary Tree 


int maxDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(root == NULL){
        return 0;
    }
    int leftVal = maxDepth(root->left);
    int rightVal = maxDepth(root->right);
    return leftVal > rightVal? leftVal+1: rightVal+1;
}