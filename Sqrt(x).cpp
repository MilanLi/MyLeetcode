// Sqrt(x)


//in order to tackle the overflow problem, we should use long long instead of int.

int sqrt(int x) {
    long long left = 0;
    long long right = x;
    long long mid;
    while(left <= right){
        mid = left + (right - left)/2;
        long long temp = mid * mid;
        if(temp > x){
            right = mid-1; //right is the answer, or it's larger than the answer.
        }
        else if(temp < x){
            left = mid+1; //left could be at most 1 larger than the answer.
        }
        else{
            return mid;
        }
    }
    return right; 
}