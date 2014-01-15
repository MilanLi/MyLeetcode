// Spiral Matrix 


vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> ret;
    int m = matrix.size();
    if(m == 0){
        return ret;
    }
    int n = matrix[0].size();
    if(n == 0){
        return ret;
    }
    ret.resize(m*n);
    ret[0] = matrix[0][0];
    int up(0), bottom(m-1), left(0), right(n-1);
    int index = 1;
    int i = 0; 
    int j = 0;
    while(index < m*n){
        while(i <= bottom && i >= up && j < right){
            j++;
            ret[index] = matrix[i][j];
            index++;
        }
        up = i+1;
        //j = right;
        
        while(i < bottom && j <= right && j >= left){
            i++;
            ret[index] = matrix[i][j];
            index++;
        }
        right = j-1;
        //i = bottom;
        
        while(i <= bottom && i >= up && j > left){
            j--;
            ret[index] = matrix[i][j];
            index++;
        }
        bottom = i-1;
        //j = left;
        
        while(i > up && j <= right && j >= left){
            i--;
            ret[index] = matrix[i][j];
            index++;
        }
        left = j+1;
        //i = up;
    }
    return ret;
}