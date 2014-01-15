// Search for a Range


vector<int> searchRange(int A[], int n, int target) {
    vector<int> ret(2, -1);
    int start = 0;
    int end = n;
    int mid;
    while(start < end){
        mid = start + (end-start)/2;
        if(A[mid] < target){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    if(A[start] != target){
        return ret;
    }
    else{
        ret[0] = start;
        end = n;
        while(start < end){
            mid = start + (end-start)/2;
            if(A[mid] > target){
                end = mid;
            }
            else{ //A[mid] == target
                start = mid+1;
            }
        }
        ret[1] = start-1;
    }
    return ret;
}