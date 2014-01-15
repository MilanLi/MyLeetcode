//Binary Tree Postorder Traversal


vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    if(root == NULL){
        return ret;
    }
    TreeNode* curr = NULL;
    vector<TreeNode*> stk;
    vector<int> value;
    stk.push_back(root);
    while(!stk.empty()){
        curr = stk.back();
        stk.pop_back();
        value.push_back(curr->val);
        if(curr->left != NULL){
            stk.push_back(curr->left);
        }
        if(curr->right != NULL){
            stk.push_back(curr->right);
        }
    }
    for(int i = (int)value.size()-1; i >= 0; i--){
        ret.push_back(value[i]);
    }
    return ret;
}