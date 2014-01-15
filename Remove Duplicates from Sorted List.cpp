// Remove Duplicates from Sorted List 


ListNode *deleteDuplicates(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->val == head->next->val){
        ListNode* temp = head->next;
        head->next = head->next->next;
        delete temp;
        return deleteDuplicates(head);
    }
    else{
        head->next = deleteDuplicates(head->next);
        return head;
    }
    
    
}