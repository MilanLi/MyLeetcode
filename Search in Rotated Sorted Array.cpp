// Search in Rotated Sorted Array


int search(int A[], int n, int target) {
    if(n == 0){
        return -1;
    }
    int left = 0;
    int right = n;
    int mid;
    int first = A[0];
    if(target == first){
            return 0;
    }
    else if(target < first){
        while(right > left){
            mid = (left+right)/2;
            if(A[mid] == target){
                return mid;
            }
            if(A[mid] < first){
                if(target < A[mid]){
                    right = mid;
                }
                else{
                    left = mid+1;
                }
            }
            else{ //first < A[mid]
                left = mid+1;
            }
        }
    }
    else{ // first < target
        while(right > left){
            mid = (left+right)/2;
            if(A[mid] == target){
                return mid;
            }
            if(A[mid] < first){
                right = mid;
            }
            else{ // A[mid] > first
                if(A[mid] < target){
                    left = mid+1;
                }
                else{ //target > A[mid]
                    right = mid;
                }
            }
        }
    }
    return -1;
}