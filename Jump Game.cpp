// Jump Game


bool canJump(int A[], int n) {
    if(n == 0){
        return false;
    }
    int start = 0;
    int target = n-1;
    int range = 0;
    while(start <= range){
        if(target - start <= A[start]){
            return true;
        }    
        range = max(start + A[start], range);
        start++;
    }
    return false;
}