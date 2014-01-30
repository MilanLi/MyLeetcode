// Construct Binary Tree from Preorder and Inorder Traversal


TreeNode* build(vector<int>& preorder, int pre, int preend, vector<int>& inorder, int in, int inend, const unordered_map<int, int>& hash){
    if(pre > preend || in > inend){
        return NULL;
    }
    int h = preorder[pre];
    int hin;
    TreeNode* head = new TreeNode(h);
    unordered_map<int, int>::const_iterator it = hash.find(h);
    if(it != hash.end()){
        hin = hash.find(h)->second;
    }
    head->left = build(preorder, pre+1, hin-in+pre, inorder, in, hin-1, hash);
    head->right = build(preorder, preend-inend+hin+1, preend, inorder, hin+1, inend, hash);
    return head;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    if(n == 0){
        return NULL;
    }
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[inorder[i]] = i;
    }
    return build(preorder, 0, n-1, inorder, 0, n-1, hash);
}