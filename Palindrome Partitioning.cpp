// Palindrome Partitioning


bool isPalin(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

void partition(string s, int start, vector<string> curr, vector<vector<string> >& ret){
    if(start == (int)s.size()){
        ret.push_back(curr);
        return;
    }
    if(start < (int)s.size()){
        for(int i = start; i < (int)s.size(); i++){
            string sub = s.substr(start, i-start+1);
            if(isPalin(sub)){
                curr.push_back(sub);
                partition(s, i+1, curr, ret);
                curr.pop_back();
            }
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > ret;
    vector<string> curr;
    partition(s, 0, curr, ret);
    return ret;
}