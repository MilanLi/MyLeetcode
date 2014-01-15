// Pascal's Triangle


vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ret;
    if(numRows <= 0){
        return ret;
    }
    int sz = ret.size();
    sz++;
    ret.resize(sz);
    ret[0].push_back(1);
    while(numRows != 1){
        ret.resize(sz+1);
        ret[sz].push_back(1);
        for(int i = 1; i < sz; i++){
            ret[sz].push_back(ret[sz-1][i-1] + ret[sz-1][i]);
        }
        ret[sz].push_back(1);
        sz++;
        numRows--;
    }
    return ret;
}


//better use less push_back and more with vector[];