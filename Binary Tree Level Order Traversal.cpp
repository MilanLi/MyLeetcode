// Binary Tree Level Order Traversal


void levelOrder(TreeNode* root, vector<vector<int> >& vec, int depth, int& maxDepth){
    if(root == NULL){
        return;
    }
    if(depth+1 > maxDepth){
        vec.resize(depth+1);
        maxDepth = depth+1;
    }
    levelOrder(root->left, vec, depth+1, maxDepth);
    levelOrder(root->right, vec, depth+1, maxDepth);
    vec[depth].push_back(root->val);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ret;
    int sz = 0;
    levelOrder(root, ret, 0, sz);
    return ret;
}