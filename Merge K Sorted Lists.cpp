// Merge K Sorted Lists


//using priority queue

class comparator{
public:
    bool operator()(ListNode* lhs, ListNode* rhs){
        return lhs->val > rhs->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if(n == 0){
        return NULL;
    }

    //take care of the pattern
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    
    vector<ListNode*>::iterator it;
    for(it = lists.begin(); it != lists.end(); ){
        if(*it == NULL){
            lists.erase(it);
        }
        else{
            pq.push(*it);
            ++it;
        }
    }
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(!pq.empty()){
        ListNode* curr = pq.top();
        pq.pop();
        if(head == NULL){
            head = curr;
            tail = curr; 
        }
        else{
            tail->next = curr;
            tail = curr;
        }
        if(curr->next != NULL){
            pq.push(curr->next);
        }
        
    }
    if(head == NULL){
        return head;
    }
    tail->next = NULL;
    return head;
    
}



class comparator{
public:
    bool operator()(const ListNode* lhs, const ListNode* rhs)const{
        return lhs->val > rhs->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if(n == 0){
        return NULL;
    }
    vector<ListNode* >::iterator it = lists.begin();
    while(it != lists.end()){
        if(*it == NULL){
            lists.erase(it);
        }
        else ++it;
    }
    //making heap
    make_heap(lists.begin(), lists.end(), comparator());
    
    ListNode* head = NULL;
    ListNode* back = NULL;
    while(lists.size() > 0){
        pop_heap(lists.begin(), lists.end(), comparator());
        if(head == NULL){
            head = lists[lists.size()-1];
            lists.pop_back();
            back = head;
        }
        else{
            back->next = lists[lists.size()-1];
            lists.pop_back();
            back = back->next;
        }
        if(back->next != NULL){
            lists.push_back(back->next);
            push_heap(lists.begin(), lists.end(), comparator());
        }
    }
    return head;
}