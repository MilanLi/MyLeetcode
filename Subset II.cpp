// Subset II


void subset(vector<vector<int> >& ret, int l, int r, vector<int>& path , vector<int>& S){
    if(l <= r){
        for(int i = l; i <= r; i++){
            if(i != l && S[i] == S[i-1]){
                continue;
            }
            path.push_back(S[i]);
            ret.push_back(path);
            subset(ret, i+1, r, path, S);
            path.pop_back();
        }
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > ret;
    int n = S.size();
    if(n == 0){
        return ret;
    }
    sort(S.begin(), S.end());
    vector<int> path;
    ret.push_back(path);
    subset(ret, 0, n-1, path, S);
    return ret;
}