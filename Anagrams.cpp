// Anagrams


//first we iterate through strs to insert every string into hashtable whose key are sorted string.
//then we iterate through the hashtable to find the vector whose size is larger than 2
//and insert that vector to the ret vector.

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    unordered_map<string, vector<string> > hash;
    unordered_map<string, vector<string> >::iterator it;
    for(int i = 0; i < (int)strs.size(); i++){
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        if((it = hash.find(strs[i])) == hash.end()){
            vector<string> vec(1, temp);
            hash[strs[i]] = vec;
        }
        else{
            it->second.push_back(temp);
        }
    }
    for(it = hash.begin(); it != hash.end(); ++it){
        if(int(it->second.size()) >= 2){
            ret.insert(ret.begin(), it->second.begin(), it->second.end());
        }
    }
    return ret;
}