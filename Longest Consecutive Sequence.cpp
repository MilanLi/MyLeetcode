// Longest Consecutive Sequence

//leverage hashtable to achieve o(n) time, 
//and introduce so called "evolve from center" thoughts

int longestConsecutive(vector<int> &num) {
    unordered_map<int, bool> hash;
    unordered_map<int, bool>::iterator it;
    int length = 1;
    for(int i = 0; i < (int)num.size(); i++){
        hash[num[i]] = true;
    }
    for(int i = 0; i < (int)num.size(); i++){
        if((it = hash.find(num[i])) != hash.end() && it->second == true){
            it->second = false;
            int l = num[i];
            int r = num[i];
            int len = 1;
            while((it = hash.find(l-1)) != hash.end()){
                it->second = false;
                l--;
                len++;
            }
            while((it = hash.find(r+1)) != hash.end()){
                it->second = false;
                r++;
                len++;
            }
            length = max(length, len);
        }
    }
    return length;
}