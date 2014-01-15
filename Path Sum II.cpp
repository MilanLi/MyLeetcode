// Path Sum II


void pathSum(TreeNode *root, int sum, vector<vector<int> >& v, vector<int> path){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                path.push_back(root->val);
                v.push_back(path);
            }
        }
        else{
            path.push_back(root->val);
            sum -= root->val;
            pathSum(root->left, sum, v, path);
            pathSum(root->right, sum, v, path);
        }
    }
}


vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ret;
    vector<int> path;
    pathSum(root, sum, ret, path);
    return ret;
}


//be sure to check if the node is leaf, although it can sum up to the given value.