// Gas Station


//if we have extra gas, we continue the end; otherwise we seek from the previous one

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int N = gas.size();
    int start = N-1;
    int end = 0;
    int extra = gas[start] - cost[start];
    while(start >= end){
        if(extra < 0){
            start--;
            extra += gas[start]-cost[start];
        }
        else{
            extra += gas[end]-cost[end];
            end++;
        }
    }
    if(extra < 0){
        return -1;
    }
    return start;
}