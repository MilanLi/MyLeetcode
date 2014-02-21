// Sort List


O(nlogn) time and O(1) space with MergeSort

ListNode *sortList(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    slow = sortList(head);
    fast = sortList(fast);
    ListNode* newHead = NULL;
    ListNode* newTail = NULL;
    while(slow && fast){
        if(slow->val <= fast->val){
            if(newHead == NULL){
                newHead = slow;
                newTail = slow;
            }
            else{
                newTail->next = slow;
                newTail = newTail->next;
            }
            slow = slow->next;
        }
        else{
            if(newHead == NULL){
                newHead = fast;
                newTail = fast;
            }
            else{
                newTail->next = fast;
                newTail = newTail->next;
            }
            fast = fast->next;
        }
    }
    newTail->next = (slow == NULL)? fast : slow;
    return newHead;
}