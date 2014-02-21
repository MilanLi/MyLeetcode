// 4Sum


vector<vector<int> > fourSum(vector<int> &num, int target) {
    int n = num.size();
    vector<vector<int> > ret;
    if(n < 4){
        return ret;
    }
    sort(num.begin(), num.end());
    for(int i = 0; i < n-3; i++){
        for(int j = i+1; j < n-2; j++){
            int currTar = target-num[i]-num[j];
            int l(j+1), r(n-1);
            vector<int> ans(4,0);
            ans[0] = num[i];
            ans[1] = num[j];
            while(r > l){
                if(num[l]+num[r] < currTar){
                    l++;
                }
                else if(num[l]+num[r] > currTar){
                    r--;
                }
                else{
                    ans[2] = num[l];
                    ans[3] = num[r];
                    ret.push_back(ans);
                    l++;
                    r--;
                    while(l < r && num[l] == num[l-1]) l++;
                    while(l < r && num[r] == num[r+1]) r--;
                }
            }
            while(j != n-3 && num[j] == num[j+1]){
                j++;
            }
        }
        while(i != n-4 && num[i] == num[i+1]){
            i++;
        }
    }
    return ret;
}