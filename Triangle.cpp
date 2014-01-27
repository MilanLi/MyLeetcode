// Triangle

//this method searches bottom-up, and only keep track of the newest values 
//o(n) space

int minimumTotal(vector<vector<int> > &triangle) {
    int depth = triangle.size();
    if(depth == 0){
        return 0;
    }
    vector<int> DP = triangle[depth-1];
    for(int i = depth-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
           DP[j] = min(DP[j], DP[j+1]) + triangle[i][j]; 
        }
    }
    return DP[0];
}

//o(n2) space

int minimumTotal(vector<vector<int> > &triangle) {
    int depth = triangle.size();
    if(depth == 0){
        return 0;
    }
    vector<vector<int> > DP = triangle;
    for(int i = depth-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
           DP[i][j] = min(DP[i+1][j], DP[i+1][j+1]) + DP[i][j]; 
        }
    }
    return DP[0][0];
}