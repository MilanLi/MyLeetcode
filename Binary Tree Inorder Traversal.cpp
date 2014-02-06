// Binary Tree Inorder Traversal


vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode*> q;
    TreeNode* curr = root;
    while(!q.empty() || curr){
        if(curr){
            q.push(curr);
            curr  = curr->left;
        }
        else{
            curr = q.top();
            q.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ret;
}

//or

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    if(root == NULL){
        return ret;
    }
    TreeNode* curr = NULL;
    vector<TreeNode*> stk;
    vector<TreeNode*> parent;
    stk.push_back(root);
    while(!stk.empty() || !parent.empty()){
        curr = stk.back();
        stk.pop_back();
        while(curr != NULL){
            parent.push_back(curr);
            if(curr->right != NULL){
                stk.push_back(curr->right);
            }
            curr = curr->left;
        }
        while(!parent.empty()){
            curr = parent.back();
            parent.pop_back();
            ret.push_back(curr->val);
            if(!stk.empty() && curr->right == stk.back()){
                break;
            }
        }
    }
    return ret;
}