// Copy with Random Pointer


RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL){
        return NULL;
    }
    RandomListNode* curr = head;
    //insert every node after itself
    while(curr != NULL){
        RandomListNode* newNode = new RandomListNode(curr->label);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    curr = head;
    //assign the random pointers
    while(curr != NULL){
        if(curr->random == NULL){ // should check if random pointer points NULL
            curr->next->random = NULL;
        }
        else{
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = head;
    RandomListNode* newhead = curr->next;
    RandomListNode* newCurr = newhead;
    //separate two linked lists apart.
    while(newCurr->next != NULL){ 
        curr->next = curr->next->next;
        newCurr->next = newCurr->next->next;
        curr = curr->next;
        newCurr = newCurr->next;
    }
    curr->next = NULL; // don' forget to assign next to NULL
    return newhead;
}