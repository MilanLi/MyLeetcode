// Combination Sum II



void combine(vector<int> & num, int start, int target, vector<int> curr, vector<vector<int> >& ret){
    if(target == 0){
        ret.push_back(curr);
        return;
    }
    if(start < (int)num.size() && target > 0){
        for(int i = start; i < (int)num.size(); i++){
            curr.push_back(num[i]);
            combine(num, i+1, target-num[i], curr, ret);
            curr.pop_back();
            while(i < (int)num.size()-1 && num[i] == num[i+1]){
                i++;
            }
        }
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > ret;
    if(num.empty()){
        return ret;
    }
    sort(num.begin(), num.end());
    vector<int> curr;
    combine(num, 0, target, curr, ret);
    return ret;
}