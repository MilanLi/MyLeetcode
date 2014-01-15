// Partition List 


ListNode *partition(ListNode *head, int x) {
    ListNode* lessStart = NULL;
    ListNode* lessEnd = NULL;
    ListNode* greatStart = NULL;
    ListNode* greatEnd = NULL;
    while(head != NULL){
        if(head->val < x){
            if(lessStart == NULL){
                lessStart = new ListNode(head->val);
                lessEnd = lessStart;
            }
            else{
                ListNode* newNode = new ListNode(head->val);
                lessEnd->next = newNode;
                lessEnd = newNode;
            }
        }
        else{
            if(greatStart == NULL){
                greatStart = new ListNode(head->val);
                greatEnd = greatStart;
            }
            else{
                ListNode* newNode = new ListNode(head->val);
                greatEnd->next = newNode;
                greatEnd = newNode;
            }
        }
        head = head->next;
    }
    if(lessStart == NULL){
        return greatStart;
    }
    lessEnd->next = greatStart;
    return lessStart;
}