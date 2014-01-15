// Unique Paths II


int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    if(m == 0){
        return 0;
    }
    int n = obstacleGrid[0].size();
    if(n == 0){
        return 0;
    }
    int array[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 0){
                if(i == 0 && j == 0){
                    array[i][j] = 1;
                }
                else if(i == 0 && j != 0){
                    array[i][j] = array[i][j-1];
                }
                else if(i != 0 && j ==  0){
                    array[i][j] = array[i-1][j];
                }
                else{
                    array[i][j] = array[i-1][j] + array[i][j-1];
                }
            }
            else{
                array[i][j] = 0;
            }
            
        }
    }
    return array[m-1][n-1];
}