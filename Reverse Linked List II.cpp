// Reverse Linked List II


//curr to keep track of the reverse portion end.
//prev to keep track of the node before reverse portion
//next to keep track of the next node to swap
//temp to keep track of next one after reverse portion
//pseudohead to keep track of the start of the reverse portion

ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(m > 1){
        prev = curr;
        curr = curr->next;
        m--;
        n--;
    }
    ListNode* next;
    ListNode* temp;
    ListNode* pseudohead = curr;
    while(n > 1 && curr->next != NULL){
        next = curr->next;
        temp = next->next;
        next->next = pseudohead;
        curr->next = temp;
        pseudohead = next;
        n--;
    }
    if(prev != NULL){
        prev->next = pseudohead;
    }
    else{
        head = pseudohead;
    }
    return head;
}