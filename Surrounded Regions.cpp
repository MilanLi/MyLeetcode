// Surrounded Regions


struct Point{
    int first;
    int second;
    Point(int a, int b): first(a), second(b){}
};

bool check(int a, int m, int b, int n){
    return a >=0 && a<m && b<n && b>=0;
}

void solve(vector<vector<char>> &board) {
    int m = board.size();
    if(m <= 2){
        return;
    }
    int n = board[0].size();
    if(n <= 2){
        return;
    }
    stack<Point> stk;
    
    for(int i = 0; i < n; i++){
        if(board[0][i] == 'O'){
            Point curr(0, i);
            stk.push(curr);
        }
        if(board[m-1][i] == 'O'){
            Point curr(m-1, i);
            stk.push(curr);
        }
    }
    for(int i = 1; i < m-1; i++){
        if(board[i][0] == 'O'){
            Point curr(i, 0);
            stk.push(curr);
        }
        if(board[i][n-1] == 'O'){
            Point curr(i, n-1);
            stk.push(curr);
        }
    }
    while(!stk.empty()){
        Point curr = stk.top();
        stk.pop();
        if(board[curr.first][curr.second] == 'O'){
            //find available around 'O' and push it into queue
            int i = curr.first;
            int j = curr.second;
            board[i][j] = '+';
            if(check(i-1, m, j, n)){
                curr.first = i-1;
                curr.second = j;
                stk.push(curr);
            }
            if(check(i+1, m, j, n)){
                curr.first = i+1;
                curr.second = j;
                stk.push(curr);
            }
            if(check(i, m, j-1, n)){
                curr.first = i;
                curr.second = j-1;
                stk.push(curr);
            }
            if(check(i, m, j+1, n)){
                curr.first = i;
                curr.second = j+1;
                stk.push(curr);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            else if(board[i][j] == '+'){
                board[i][j] = 'O';
            }
        }
    }
}