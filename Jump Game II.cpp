// Jump Game II

//fail for any recursion, even combining with Dynamic Programming
//DP[i] keep track of the farthest place can reach


int jump(int A[], int n) {
    if(n <= 1){
        return 0;
    }
    int step = 1;
    int DP[n];
    int start;
    DP[0] = 0;
    DP[1] = A[0];
    while(DP[step] < n-1){
        start = DP[step-1];
        DP[step+1] = 0;
        for(int i = start+1; i <= DP[step]; i++){
            if(A[i]+i > DP[step]){
                DP[step+1] = max(A[i]+i, DP[step+1]);
            }
        }
        step++;
    }
    return step;
}