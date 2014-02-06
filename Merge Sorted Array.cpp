// Merge Sorted Array

void merge(int A[], int m, int B[], int n) {
    int pa(m-1), pb(n-1), index(m+n-1);
    while(pa >= 0 && pb >= 0){
        if(A[pa] <= B[pb]){
            A[index--] = B[pb--];
        }
        else{
            A[index--] = A[pa--];
        }
    }
    if(pa < 0){
        while(pb >= 0){
            A[index--] = B[pb--];
        }
    }
}