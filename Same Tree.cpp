// Same Tree


bool isSameTree(TreeNode *p, TreeNode *q) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(p == NULL && q == NULL){
        return true;
    }
    if(!(p != NULL && q != NULL) || (p->val != q->val)){
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}		