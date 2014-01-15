// Binary Tree Preorder Traversal 


vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    if(root == NULL){
        return ret;
    }
    TreeNode* curr = NULL;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while(!stk.empty()){
        curr = stk.back();
        stk.pop_back();
        ret.push_back(curr->val);
        if(curr->right != NULL){
            stk.push_back(curr->right);
        } 
        if(curr->left != NULL){
            stk.push_back(curr->left);
        }
    }
    return ret;
}