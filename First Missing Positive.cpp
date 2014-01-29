// First Missing Positive


//we iterate through the list, swap the current element to the correct position
//iterate the second time to find the first missing positive number

int firstMissingPositive(int A[], int n) {
    int index = 0;
    while(index < n){
        if(A[index] <= n && A[index] > 0){
            if(A[index] == index+1){
                index++;
            }
            else{
                int temp = A[index];
                if(A[temp-1] == temp){ // do nothing if there is a correct element there
                    index++;
                }
                else{
                    A[index] = A[temp-1];
                    A[temp-1] = temp;
                }
            }
        }
        else{
            index++;
        }
    }
    for(int i = 0; i < n; i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    return n+1;
}