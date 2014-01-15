// Populating Next Right Pointers in Each Node


void connect(TreeLinkNode *root) {
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        root->left->next = root->right;
        if(root->next != NULL){
            root->right->next = root->next->left;
        }
    }
    connect(root->left);
    connect(root->right);
}