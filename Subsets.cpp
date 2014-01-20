// Subsets


// use the binary number to indicate which elements we want and which don't
//10101 means the subset includes the first, third and fifth elements in S
//we iterate from 0 to (2^size)-1 to get every situation across

vector<int> num2subset(vector<int>& S, int num){
    vector<int> ret;
    int i = 0;
    while(num != 0){
        int temp = num & 1;
        if(temp == 1){
            ret.push_back(S[i]);
        }
        num = num >> 1;
        i++;
    }
    return ret;
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ret;
    int sz = S.size();
    if(sz == 0){
        return ret;
    }
    sort(S.begin(), S.end());
    for(int num = 0; num < pow(2, sz); num++){
        ret.push_back(num2subset(S, num));
    }
    return ret;
    
}