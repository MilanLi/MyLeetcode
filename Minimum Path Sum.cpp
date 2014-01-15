// Minimum Path Sum


int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    if(m == 0){
        return 0;
    }
    int n = grid[0].size();
    int array[m][n];
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == m-1 && j == n-1){
                array[m-1][n-1] = grid[m-1][n-1];
            }
            else if(i == m-1){
                array[i][j] = grid[i][j] + array[i][j+1];
            }
            else if(j == n-1){
                array[i][j] = grid[i][j] + array[i+1][j];
            }
            else{
                array[i][j] = grid[i][j] + min(array[i][j+1], array[i+1][j]);
            }
        }
    }
    return array[0][0];
}