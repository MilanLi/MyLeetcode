// Candy


int candy(vector<int> &ratings) {
    int sz = ratings.size();
    if(sz == 0){
        return 0;
    }
    int ret = 0;
    vector<int> candy(sz, 1);
    for(int i = 1; i < sz; i++){
        if(ratings[i] > ratings[i-1]){
            candy[i] = candy[i-1]+1;
        }
    }
    for(int i = sz-2; i >= 0; i--){
        if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
            candy[i] = candy[i+1]+1;
        }
        ret += candy[i+1];
    }
    ret += candy[0];
    return ret;
}