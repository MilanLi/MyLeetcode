// Remove Duplicates from Sorted Array II


int removeDuplicates(int A[], int n) {
    if(n <= 0){
        return n;
    }
    int index = 1;
    int last = A[0];
    int many = 1;
    int upper = n;
    for(int i = 1; i < upper; i++){
        if(A[i] == last){
            many++;
            if(many <= 2){
                A[index] = A[i];
                index++;
            }
            else{
                n--;
            }
        }
        else{
            A[index] = A[i];
            index++;
            many = 1;
            last = A[i];
        }
    }
    return n;
}