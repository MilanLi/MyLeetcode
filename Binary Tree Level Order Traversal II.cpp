// Binary Tree Level Order Traversal II 
//bottom up


void levelOrderBottom(TreeNode* root, vector<vector<int> >& vec, int depth, int& maxDepth){
    if(root == NULL){
        return;
    }
    if(depth+1 > maxDepth){
        vec.resize(depth+1);
        maxDepth = depth+1;
    }
    levelOrderBottom(root->left, vec, depth+1, maxDepth);
    levelOrderBottom(root->right, vec, depth+1, maxDepth);
    vec[depth].push_back(root->val);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > ret;
    int sz = 0;
    levelOrderBottom(root, ret, 0, sz);
    for(int i = 0; i < sz/2; i++){
        vector<int> temp = ret[i];
        ret[i] = ret[sz-i-1];
        ret[sz-i-1] = temp;
    }
    return ret;
}