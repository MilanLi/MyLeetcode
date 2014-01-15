// Best Time to Buy and Sell Stock


int maxProfit(vector<int> &prices) {
    if(prices.empty()){
        return 0;
    }
    int min = prices[0];
    int profit = 0;
    for(int i = 0; i < (int)prices.size(); i++){
        if(prices[i] < min){
            min = prices[i];
        }
        int temp = prices[i] - min;
        if(temp > profit){
            profit = temp;
        }
    }
    return profit;
}