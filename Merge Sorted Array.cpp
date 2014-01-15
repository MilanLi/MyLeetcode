// Merge Sorted Array

//This is a method merging from the smallest number.
// There is another method merging from the largest which is much earsier.

void merge(int A[], int m, int B[], int n) {
    if(n == 0){
        return;
    }
    if(m == 0){
        for(int i = 0; i < n; i ++){
            A[i] = B[i];
        }
        return;
    }
    for(int i = m+n-1; i >=n; i--){
        A[i] = A[i-n];
    }
    int i = n;
    int j = 0;
    int index = 0;
    while(1){
        if(A[i] > B[j]){
            A[index] = B[j];
            j++;
        }
        else{
            A[index] = A[i];
            i++;
        }
        index++;
        if(i == m+n){
            for(; j < n ; j++, index++){
                A[index] = B[j];
            }
            break;
        }
        else if(j == n){
            for(; i < m+n; i++, index++){
                A[index] = A[i];
            }
            break;
        }
    }
}