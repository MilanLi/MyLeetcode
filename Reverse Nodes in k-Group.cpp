// Reverse Nodes in k-Group


ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode* curr = head;
    int n = 0;
    while(curr){
        n++;
        curr = curr->next;
    }
    if(n < k || k <= 1){
        return head;
    }
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    ListNode* prev = newHead;
    ListNode* next;
    curr = head;
    int count;
    while(n >= k){
        count = 1;
        while(count < k){
            next = curr->next;
            ListNode* temp = next->next;
            next->next = prev->next;
            prev->next = next;
            curr->next = temp;
            count++;
        }
        n -= k;
        prev = curr;
        curr = curr->next;
    }
    head = newHead->next;
    delete newHead;
    return head;
}