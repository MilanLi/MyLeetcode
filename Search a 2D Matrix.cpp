// Search a 2D Matrix 


bool searchMatrix(vector<vector<int> > &matrix, int target, int rowBegin, int rowEnd, int colBegin, int colEnd){
    if(rowBegin == rowEnd || colBegin == colEnd){
        return false;
    }
    if(rowBegin + 1 != rowEnd){
        int rowMid = (rowBegin+rowEnd)/2;
        if(matrix[rowMid][0] > target){
            return searchMatrix(matrix, target, rowBegin, rowMid, colBegin, colEnd);
        }
        else if(matrix[rowMid][0] < target){
            if(matrix[rowMid][colEnd-1] < target){
                return searchMatrix(matrix, target, rowMid+1, rowEnd, colBegin, colEnd);
            }
            if(matrix[rowMid][colEnd-1] == target){
                return true;
            }
            else{
                return searchMatrix(matrix, target, rowMid, rowMid+1, colBegin, colEnd);
            }
        }
        else{
            return true;
        }
    }
    else{
        if(colBegin + 1 == colEnd){
            return matrix[rowBegin][colBegin] == target;
        }
        int colMid = (colBegin + colEnd)/2;
        if(matrix[rowBegin][colMid] > target){
            return searchMatrix(matrix, target, rowBegin, rowEnd, colBegin, colMid);
        }
        else if(matrix[rowBegin][colMid] < target){
            return searchMatrix(matrix, target, rowBegin, rowEnd, colMid, colEnd);
        }
        else{
            return true;
        }
    }
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.empty()){
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    return searchMatrix(matrix, target, 0, m, 0, n);
}