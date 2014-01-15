// Gray Code


vector<int> grayCode(int n) {
    vector<int> ret;
    if(n == 0){
        ret.push_back(0);
        return ret;
    }
    ret.push_back(0);
    ret.push_back(1);
    int power = 1;
    while(n != 1){
        power *= 2;
        for(int i = power -1; i >= 0; i--){
            ret.push_back(ret[i] + power);
        }
        n--;
    }
    return ret;
}