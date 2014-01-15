// Search Insert Position


int searchInsert(int A[], int n, int target) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(n == 0){
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(A[i] >= target){
            return i;
        }
    }
    return n;
}