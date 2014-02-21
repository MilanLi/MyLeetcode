// Maximal Rectangle


int maximalRectangle(vector<vector<char> > &matrix) {
    int m = matrix.size();
    if(m == 0){
        return 0;
    }
    int n = matrix[0].size();
    if(n== 0){
        return 0;
    }
    int area = 0;
    vector<int> H(n, 0);
    vector<int> L(n, 0);
    vector<int> R(n, n-1);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '0'){
                H[j] = 0;
                L[j] = 0;
                R[j] = n-1;
            }
            else{
                H[j] = H[j]+1;
                //find the position of after left 0
                int left = j;
                for(; left >= 0; left--){
                    if(matrix[i][left] == '0'){
                        break;
                    }
                }
                L[j] = max(L[j], left+1);
                //find the position of before right 0
                int right = j;
                for(; right < n; right++){
                    if(matrix[i][right] == '0'){
                        break;
                    }
                }
                R[j] = min(R[j], right-1);
                area = max(area, H[j]*(R[j]-L[j]+1));
            }
        }
    }
    return area;
}