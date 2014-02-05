// N-Queens II


int queens(vector<int> columns, int n){
    int row, col, ret(0);
    row = columns.size();
    if(row == n){
        return 1;
    }
    for(col = 0; col < n; col++){
        if(check(columns, row, col)){
            columns.push_back(col);
            ret += queens(columns, n);
            columns.pop_back();
        }
    }
    return ret;
}

bool check(vector<int> columns, int row, int col){
    if(columns.empty()){
        return true;
    }
    for(int i = 0; i < columns.size(); i++){
        int coldiff = abs(col - columns[i]);
        if(coldiff == 0){
            return false;
        }
        int rowdiff = abs(row - i);
        if(rowdiff == coldiff){
            return false;
        }
    }
    return true;
}

int totalNQueens(int n) {
    vector<int> columns;
    if(n == 0){
        return 0;
    }
    return queens(columns, n);
}