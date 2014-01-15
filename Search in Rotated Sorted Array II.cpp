// Search in Rotated Sorted Array II 


bool search(int A[], int n, int target) {
    if(n == 0){
        return false;
    }
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(A[mid] == target){
            return true;
        }
        if(A[start] < A[mid]){ //left part is sorted
            if(A[mid] > target && A[start] <= target){	
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else if(A[start] > A[mid]){ // right part is sorted
            if(A[mid] < target && A[end] >= target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        else{
            start++;
        }
    }
    return false;
}