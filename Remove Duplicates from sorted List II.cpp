// Remove Duplicates from sorted List II


ListNode *deleteDuplicates(ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    ListNode** curr = &head;
    ListNode* fast = head->next;
    int num = 1;
    while(fast != NULL){
        if(fast->val == (*curr)->val){
            //fast = fast->next;
            num++;
        }
        else{
            if(num > 1){
                (*curr) = fast;
                num = 1;
            }
            else{
                curr = &(*curr)->next;
            }
        }
        fast = fast->next;
    }
    if(num > 1){
        (*curr) = fast;
    }
    return head;
}