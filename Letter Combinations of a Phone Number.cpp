// Letter Combinations of a Phone Number


vector<string> letterCombinations(string digits) {
    vector<string> ret;
    int n = digits.size();
    if(n == 0){
        ret.push_back("");
        return ret;
    }
    int count = 0;
    const string str[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < n; i++){
        int index = digits[i]-'0';
        string temp = str[index];
        int len = temp.size();
        if(count == 0){
            for(int j = 0; j < len; j++){
                string curr(1, temp[j]);
                ret.push_back(curr);
            }
            count = len;
        }
        else{
            ret.resize(count*len);
            for(int k = 0; k < count; k++){
                string tt = ret[k];
                for(int j = 0; j < len; j++){
                    ret[j*count+k] = tt+temp[j];
                }
            }
            count *= len;
        }
    }
    return ret;
}