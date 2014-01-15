// Linked List Cycle II 


ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            ListNode* circle = head;
            while(circle != slow){
                circle = circle->next;
                slow = slow->next;
            }
            return circle;
        }
    }
    return NULL;
}