// Unique Binary Search Trees


int numTrees(int n) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int* array = new int[n];
    array[0] = 1;
    for(int i = 1; i < n; i ++){
        array[i] = numTrees(i);
    }
    int ret = 0;
    for(int i = 0; i < n; i++){
        ret += array[i] * array[n-i-1];
    }
    return ret;
}

//for number n, the permutation above it * permutation below it.
//need rewrite