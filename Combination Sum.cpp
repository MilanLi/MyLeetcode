// Combination Sum


//act like getting changes. 
//sorting to make the sequence non-descending order.
//if index one is the same as index-1 one, then skip this element.

void combine(vector<int> &candidates, int index, int sz, vector<int> current, int target, vector<vector<int> >& ret){
    if(index < sz && candidates[index] <= target){
        if(candidates[index] == target){
            current.push_back(target);
            ret.push_back(current);
        }
        else if(index > 0 && candidates[index] == candidates[index-1]){
            combine(candidates, index+1, sz, current, target, ret);
        }
        else{
            combine(candidates, index+1, sz, current, target, ret);
            current.push_back(candidates[index]);
            combine(candidates, index, sz, current, target-candidates[index], ret);
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > ret;
    int sz = candidates.size();
    if(sz == 0){
        return ret;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> initial;
    combine(candidates, 0, sz, initial, target, ret);
    return ret;
}