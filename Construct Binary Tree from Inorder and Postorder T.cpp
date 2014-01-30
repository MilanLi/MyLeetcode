// Construct Binary Tree from Inorder and Postorder Traversal



TreeNode* build(vector<int>& inorder, int in, int inend, vector<int>& postorder, int post, int postend, const unordered_map<int, int>& hash){
    if(in > inend || post > postend){
        return NULL;
    }
    int h = postorder[postend];
    TreeNode* head = new TreeNode(h);
    int hin = hash.find(h)->second;
    head->left = build(inorder, in, hin-1, postorder, post, post+hin-1-in, hash);
    head->right = build(inorder, hin+1, inend, postorder, postend+hin-inend, postend-1, hash);
    return head;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if(n == 0){
        return NULL;
    }
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[inorder[i]] = i;
    }
    return build(inorder, 0, n-1, postorder, 0, n-1, hash);
}