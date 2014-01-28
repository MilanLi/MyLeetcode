// Longest Substring Without Repeating Characters


//

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> used;
    unordered_map<char, int>::iterator it;
    int len = 0;
    int start = 0;
    int i;
    for(i = 0; i < (int)s.length(); i++){
        if((it = used.find(s[i])) == used.end()){
            used[s[i]] = i;
        }
        else{
            len = max(len, i-start);
            for(int j = start; j < it->second; j++){
                used.erase(s[j]);
            }
            start = it->second+1; //need to update to be the newest
            it->second = i;
        }
    }
    len = max(len, i-start); //handle if the substring is at the back of string
    return len;
}