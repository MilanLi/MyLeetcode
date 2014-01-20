// Trapping Rain Water

// the basic idea is that the amount of water at i is dertermined by the leftmost height and 
// the rightmost height, if min(left, right) > A[i], the water at i is level - A[i];

// so we first search from left to right, to find the leftmostheight at each i,
//then we search from right to left, calculate the rightmostheight at i and by the way,
// calculate the amount of water that can contain at i


int trap(int A[], int n) {
    if(n <= 2){
        return 0;
    }
    int water = 0;
    int leftMost[n];
    leftMost[0] = 0;
    int lmax = INT_MIN;
    for(int i = 1; i < n; i++){
        lmax = max(lmax, A[i-1]);
        leftMost[i] = lmax;
    }
    int rmax = A[n-1];
    for(int i = n-2; i >=0; i--){
        rmax = max(rmax, A[i+1]);
        int level = min(leftMost[i], rmax);
        if(level > A[i]){
            water += level - A[i];
        }
    }
    return water;
}