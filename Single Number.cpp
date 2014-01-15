//Single Number

int singleNumber(int A[], int n) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int ret = A[0];
    for(int i = 1; i < n; i++){
        ret = ret ^ A[i];
    }
    return ret;
}