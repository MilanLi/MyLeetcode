// Remove Nth Node From End of List


ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(head == NULL || n <= 0){
        return head;
    }
    int num = 1;
    ListNode** rm = &head;
    ListNode* curr = head->next;
    while(curr != NULL){
        if(num < n){
            num++;
        }
        else{
            rm = &(*rm)->next;
        }
        curr = curr->next;
    }
    if(num == n){
        ListNode* temp = (*rm);
        (*rm) = (*rm)->next;
        delete temp;
    }
    return head;
}