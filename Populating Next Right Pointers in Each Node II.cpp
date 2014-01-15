// Populating Next Right Pointers in Each Node II


void connect(TreeLinkNode *root) {
    while (root) {
        TreeLinkNode * next = NULL; // the first node of next level
        TreeLinkNode * prev = NULL; // previous node on the same level
        for (; root; root=root->next) {
            if (!next) next = root->left?root->left:root->right;

            if (root->left) {
                if (prev) prev->next = root->left;
                prev = root->left;
            }
            if (root->right) {
                if (prev) prev->next = root->right;
                prev = root->right;
            }
        }
        root = next; // turn to next level
    }
}