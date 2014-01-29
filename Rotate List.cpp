// Rotate List


ListNode *rotateRight(ListNode *head, int k) {
    if(head == NULL){
        return NULL;
    }
    int sz = 0;
    ListNode* curr = head;
    ListNode* end;
    while(curr != NULL){
        sz++;
        end = curr;
        curr = curr->next;
    }
    int n = sz - k % sz; // 0 % 0 is illegal
    ListNode* prev;
    curr = head;
    while(n-- > 0){
        prev = curr;
        curr = curr->next;
    }
    if(curr != NULL){
        prev->next = NULL;
        end->next = head;
        head = curr;
    }
    return head;
}