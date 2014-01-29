// Merge K Sorted Lists


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