// Add Two Numbers


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int carry = 0;
    while(l1 || l2){
        int res;
        if(l1 && l2){
            res = carry+ l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1 == NULL){
            res = carry + l2->val;
            l2 = l2->next;
        }
        else{
            res = carry + l1->val;
            l1 = l1->next;
        }
        
        if(res > 9){
            res -= 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        if(head == NULL){
            head = new ListNode(res);
            tail = head;
        }
        else{
            tail->next = new ListNode(res);
            tail = tail->next;
        }
    }
    if(carry == 1){
        tail->next = new ListNode(carry);
        tail = tail->next;
    }
    return head;
}