LRU Cache



class LRUCache{
private:
    struct ListNode{
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v): key(k), val(v), prev(NULL), next(NULL){};
    };

    unordered_map<int, ListNode* > cache;
    unordered_map<int, ListNode* >::iterator it;
    ListNode* head;
    ListNode* back;
    int sz;
    int cp;
    
    void update(ListNode* curr){
        if(curr->next == NULL){
            return;
        }
        if(curr->prev == NULL){
            head = curr->next;
            curr->next->prev = NULL;
            curr->next = NULL;
            back->next = curr;
            curr->prev = back;
            back = back->next;
        }
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = NULL;
            curr->prev = back;
            back->next = curr;
            back = back->next;
        }
    }

public:
    LRUCache(int capacity) {
        sz = 0;
        cp = capacity;
        head = NULL;
        back = NULL;
    }
    
    int get(int key) {
        it = cache.find(key);
        if(it == cache.end()){
            return -1;
        }
        ListNode* curr = it->second;
        update(curr);
        return curr->val;
    }
    
    void set(int key, int value) {
        it = cache.find(key);
        if(it == cache.end()){
            if(sz < cp){
                sz++;
            }
            else{
                ListNode* temp = head;
                cache.erase(temp->key);
                if(head->next != NULL){
                    head = head->next;
                    head->prev = NULL;
                    //delete temp;
                }
                else{
                    head = NULL;
                    back = NULL;
                }
                delete temp;
            }
            if(head == NULL){
                head = new ListNode(key, value);
                back = head;
            }
            else{
                back->next = new ListNode(key, value);
                back->next->prev = back;
                back = back->next;
            }
            cache[key] = back;
        }
        else{
            ListNode* curr = it->second;
            update(curr);
            curr->val = value;
        }
    }
};