// Longest Common Prefix


string longestCommonPrefix(vector<string> &strs) {
    string ret = "";
    int num = strs.size();
    if(num == 0){
        return ret;
    }
    vector<int> sz;
    for(int i = 0; i < num; i++){
        sz.push_back(strs[i].size());
    }
    int index = 0;
    while(1){
        for(int i = 0; i < num; i++){
            if(index == sz[i]){
                return ret;
            }
        }
        char ch = strs[0][index];
        for(int i = 0; i < num; i++){
            if(strs[i][index] != ch){
                return ret;
            }
        }
        ret += ch;
        index++;
    }
}