// Maximum Subarray


int maxSubArray(int A[], int n) {
    int ret(A[0]), sum(0);
    for(int i = 0; i < n; i++){
        sum = max(sum + A[i], A[i]);
        ret = max(sum, ret);
    }
    return ret;
}



// another method
int maxSubArray(int A[], int begin, int end){
    if(begin == end){
        return 0;
    }
    if(begin + 1 == end){
        return A[begin];
    }
    
    int mid = (begin + end)/2;
    int leftMax = maxSubArray(A, begin, mid);
    int rightMax = maxSubArray(A, mid, end);
    int leftBorderMax(INT_MIN), rightBorderMax(INT_MIN);
    int leftSum(0), rightSum(0);
    for(int i = mid-1; i >= begin; i--){
        leftSum += A[i];
        if(leftSum > leftBorderMax){
            leftBorderMax = leftSum;
        }
    }
    for(int i = mid; i < end; i++){
        rightSum += A[i];
        if(rightSum > rightBorderMax){
            rightBorderMax = rightSum;
        }
    }
    return max(max(leftMax, rightMax), leftBorderMax + rightBorderMax);
}

int maxSubArray(int A[], int n) {
    return maxSubArray(A, 0, n);
}