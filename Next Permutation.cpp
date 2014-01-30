// Next Permutation


void swap(vector<int>& num, int a, int b){
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

void nextPermutation(vector<int> &num) {
    int n = num.size();
    if(n <= 1){
        return;
    }
    int left = -1;
    for(int i = 0; i < n-1; i++){ // find the largest index i that num[i] < num[i+1]
        if(num[i] < num[i+1]){
            left = i;
        }
    }
    if(left == -1){
        for(int i = 0; i < n/2; i++){ //if not exist, change to the least permutation
            swap(num, i, n-1-i);
        }
        return;
    }
    int temp = left+1;
    for(int j = left+1; j < n; j++){ // find the largest index k that num[i] < num[k]
        if(num[left] < num[j]){
            temp = j;
        }
    }
    swap(num, left, temp);
    for(int k = left+1; k < (n+left+1)/2; k++){ //reverse from i+1 to the last element
        swap(num, k, n+left-k);
    }
}