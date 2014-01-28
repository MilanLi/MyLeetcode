// Permutation II


//if there is no duplication, set is not need; otherwise we must keep track
// which elements have been used as the head element

void swap(vector<int>& num, int a, int b){
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}
void permute(vector<int>& num, int start, int end, vector<vector<int> >& ret){
    if(start == end){
        ret.push_back(num);
        return;
    }
    unordered_set<int> used;
    permute(num, start+1, end, ret);
    for(int i = start+1; i <= end; i++){
        if(num[start] != num[i] && used.find(num[i]) == used.end()){
            swap(num, start, i);
            //ret.push_back(num);
            permute(num, start+1, end, ret);
            swap(num, start, i);
            used.insert(num[i]);
        }
    }
}
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > ret;
    int sz = num.size();
    permute(num, 0, sz-1, ret);
    return ret;
}