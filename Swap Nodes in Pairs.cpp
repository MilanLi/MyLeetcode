// Swap Nodes in Pairs


ListNode *swapPairs(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead = head->next;
    ListNode* tempNode = head->next->next;
    newHead->next = head;
    head->next = swapPairs(tempNode);
    head = newHead;
    return head;
}