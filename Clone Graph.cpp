// Clone Graph


UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL){
        return NULL;
    }
    unordered_set<int> s;
    unordered_map<int, UndirectedGraphNode*> hash;
    unordered_map<int, UndirectedGraphNode*>::iterator it;
    queue<UndirectedGraphNode*> q;
    UndirectedGraphNode* curr;
    UndirectedGraphNode* newCurr;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    hash[root->label] = root;
    q.push(node);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        //check if the node is already visited.
        if(s.find(curr->label) != s.end()){
            continue;
        }
        s.insert(curr->label);
        newCurr = hash[curr->label];
        for(int i = 0; i < (int)curr->neighbors.size(); i++){
            UndirectedGraphNode* temp = curr->neighbors[i];
            it = hash.find(temp->label);
            
            //check if the node was constructed.
            if(it == hash.end()){
                UndirectedGraphNode* newNode = new UndirectedGraphNode(temp->label);
                hash[temp->label] = newNode;
                newCurr->neighbors.push_back(newNode);
            }
            else{
                //check if it points itself
                if(it->second == newCurr){
                    newCurr->neighbors.push_back(newCurr);
                }
                else{
                    newCurr->neighbors.push_back(it->second);
                }
            }
            q.push(temp);
        }
    }
    return root;
}