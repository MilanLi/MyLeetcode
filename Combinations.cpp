// Combinations

//Everytime we choose one element i from [1, n], 
//and then we recursively choose k-1 elements from [i+1,n]


void combine(int start, int end, int k, vector<int>& current, vector<vector<int> >& ret){
    if(end < start+k-1){
        return;
    }
    if(k != 0){
        for(int i = start; i <= end-k+1; i++){
            vector<int> temp = current;
            temp.push_back(i);
            combine(i+1, end, k-1, temp, ret);
        }
    }
    else{
        ret.push_back(current);
    }
    
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ret;
    vector<int> current;
    combine(1, n, k, current, ret);
    return ret;
}