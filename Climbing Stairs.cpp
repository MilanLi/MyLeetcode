// Climbing Stairs


int climbStairs(int n) {
    if(n == 1 || n == 0){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int ret;
    int p = 1;
    int q = 2;
    for(int i = 2; i < n-1; i++){
        int temp = p + q;
        if(p > q) q = temp;
        else p = temp;
    }
    return p + q;
}