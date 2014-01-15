// Set Matrix Zeroes


void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    if(m == 0){
        return;
    }
    int n = matrix[0].size();
    bool firstRowHasZero(false), firstColHasZero(false);
    
    //check if the first row has zero
    for(int j = 0; j < n; j++){
        if(matrix[0][j] == 0){
            firstRowHasZero = true;
            break;
        }
    }
    
    //check if the first column has zero
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
            firstColHasZero = true;
            break;
        }
    }

    //if it is zero, set the corresponding coordinates to be zero, because sooner or later if will be zero
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    //for each element, check if it should be set zero
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    
    //check if the first row should be zero
    if(firstRowHasZero){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }
    
    if(firstColHasZero){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
}