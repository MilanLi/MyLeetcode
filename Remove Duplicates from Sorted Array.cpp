// Remove Duplicates from Sorted Array


int removeDuplicates(int A[], int n) {
    if(n == 0){
        return 0;
    }
    int i = 0;
    int last;
    int index = 1;
    int upper = n;
    while(i < upper){
        if(i != 0){
            if(A[i] == last){
                n--;
            }
            else{
                A[index] = A[i];
                index++;    
            }
        }
        last = A[i];
        i++;
        
    }
    return n;
}