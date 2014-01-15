// 3Sum Closest


int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int sum = num[0] + num[1] + num[2];
    for(int i = 0; i < (int)num.size()-2; i++){
        int start = i + 1;
        int end = num.size()-1;
        while(end > start){
            int temp = num[i] + num[start] + num[end];
            if(temp == target){
                return target;
            }
            if(abs(temp - target) < abs(sum - target)){
                sum = temp;
            }
            if(temp < target){
                start++;
            }
            else{
                end--;
            }
        }
    }
    return sum;
}