// Convert Sorted Array to Binary Search Tree 


TreeNode* sortedArrayToBST(vector<int> &num, int begin, int end){
    if(end == begin){
        return NULL;
    }
    int mid = (end + begin)/2;
    TreeNode* root = new TreeNode(num[mid]);
    root->left = sortedArrayToBST(num, begin, mid);
    root->right = sortedArrayToBST(num, mid+1, end);
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    return sortedArrayToBST(num, 0, (int)num.size());
    
}