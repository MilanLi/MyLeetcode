// Count and Say


string countAndSay(int n) {
    string ret = "";
    if(n <= 0){
        return ret;
    }
    ret += '1';
    int sz = 1;
    while(n > 1){
        int num = 1;
        stringstream ss;
        char ch = ret[0];
        for(int i = 1; i < sz; i++){
            if(ret[i] == ch){
                num++;
            }
            else{
                ss << num;
                ss << ch;
                num = 1;
                ch = ret[i];
            }
        }
        ss << num;
        ss << ch;
        ret = ss.str();
        n--;
        sz = ret.size();
    }
    return ret;
}