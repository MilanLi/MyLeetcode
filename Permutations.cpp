// Permutations


void swap(vector<int>& num, int a, int b){
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

void permute(vector<int> num, vector<vector<int> > &vec, int begin, int end){
    if(begin == end){
        return;
    }
    if(begin+1 == end){
        vec.push_back(num);
        return;
    }
    permute(num, vec, begin+1, end);
    for(int i = begin + 1; i < end; i++){
        if(num[begin] != num[i]){
            swap(num, begin, i);
            permute(num, vec, begin+1, end);
        }
        swap(num, begin, i);
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ret;
    permute(num, ret, 0, num.size());
    return ret;
}