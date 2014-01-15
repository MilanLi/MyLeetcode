// Convert Sorted List to Binary Search Tree


TreeNode* sortedListToBST(ListNode*& head, int start, int end){
    if(start == end){
        return NULL;
    }
    int mid = start + (end - start)/2;
    TreeNode* leftChild = sortedListToBST(head, start, mid);
    TreeNode* parent = new TreeNode(head->val);
    parent->left = leftChild;
    head = head->next;
    parent->right = sortedListToBST(head, mid+1, end);
    return parent;
}

TreeNode *sortedListToBST(ListNode *head) {
    int n = 0;
    ListNode* list = head;
    while(list != NULL){
        n++;
        list = list->next;
    }
    return sortedListToBST(head, 0, n);
}


//construct with postorder traversal.
//use start and end to indicate which is children and which is parent.
// but in linked list, traverse in order.