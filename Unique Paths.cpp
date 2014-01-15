// Unique Paths


int uniquePaths(int m, int n) {
    vector<vector<int> > array;
    array.resize(m);
    for(int i = 0; i < m; i++){
        array[i].resize(n);
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0){
                array[i][j] = 1;
            }
            else{
                array[i][j] = array[i-1][j] + array[i][j-1];
            }
        }
    }
    return array[m-1][n-1];
}