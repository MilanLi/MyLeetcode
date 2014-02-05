// N-Queens


void queens(vector<int> columns, int n, vector<vector<string> >& ret){
    int row, col;
    row = columns.size();
    if(row == n){
        string s(n, '.');
        vector<string> temp(n, s);
        for(int i = 0; i < n; i++){
            temp[i][columns[i]] = 'Q';
        }
        ret.push_back(temp);
        return;
    }
    for(col = 0; col < n; col++){
        if(check(columns, row, col)){
            columns.push_back(col);
            queens(columns, n, ret);
            columns.pop_back();
        }
    }
    return;
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

vector<vector<string> > solveNQueens(int n) {
    vector<int> columns;
    vector<vector<string> > ret;
    if(n == 0){
        return ret;
    }
    queens(columns, n, ret);
    return ret;
}