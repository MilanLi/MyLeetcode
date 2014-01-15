// Spiral Matrix II


vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ret;
    if(n == 0){
        return ret;
    }
    ret.resize(n);
    for(int i = 0; i < n; i++){
        ret[i] = vector<int>(n, 0);
    }
    int max = n*n;
    int index = 1;
    int row(0), col(0);
    ret[row][col] = index++;
    while(1){
        while(col+1 < n && ret[row][col+1] == 0){
            col++;
            ret[row][col] = index++;
        }
        while(row+1 < n && ret[row+1][col] == 0){
            row++;
            ret[row][col] = index++;
        }
        while(col-1 >= 0 && ret[row][col-1] == 0){
            col--;
            ret[row][col] = index++;
        }
        while(row-1 >= 0 && ret[row-1][col] == 0){
            row--;
            ret[row][col] = index++;
        }
        if(index > max){
            return ret;
        }
    }
}