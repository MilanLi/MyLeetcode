// Unique Binary Search Tree II


//vector copy takes considerable amount of time. we instead use pointer to vector to save time.

vector<TreeNode*>* generate(int l, int r){
    vector<TreeNode*>* ret = new vector<TreeNode*>;
    if(l > r){
        ret->push_back(NULL);
        return ret;
    }
    if(l == r){
        TreeNode* newNode = new TreeNode(l);
        ret->push_back(newNode);
        return ret;
    }
    for(int index = l; index <= r; index++){
        vector<TreeNode*>* leftSub = generate(l, index-1);
        vector<TreeNode*>* rightSub = generate(index+1, r);
        for(int i = 0; i < (int)leftSub->size(); i++){
            for(int j = 0; j < (int)rightSub->size(); j++){
                TreeNode* root = new TreeNode(index);
                root->left = leftSub->at(i);
                root->right = rightSub->at(j);
                ret->push_back(root);
            }
        }
    }
    return ret;
}

vector<TreeNode *> generateTrees(int n) {
    return *generate(1, n);
}