// Insertion Sort List


ListNode *insertionSortList(ListNode *head) {
    ListNode* ret = NULL;
    while(head != NULL){
        if(ret == NULL){
            ret = head;
            head = head->next;
            ret->next = NULL;
        }
        else{
            ListNode** ins = &ret;
            while(*ins != NULL){
                if((*ins)->val <= head->val){
                    ins = &(*ins)->next;
                }
                else{// be sure to break if find the right the place to insert
                    break;
                }
            }
            ListNode* temp = head->next;
            ListNode* track = *ins;
            *ins = head;
            head->next = track;
            head = temp;
        }
    }
    return ret;
}