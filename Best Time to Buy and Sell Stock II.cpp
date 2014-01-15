// Best Time to Buy and Sell Stock II


int maxProfit(vector<int> &prices) {
    int ret = 0;
    if(prices.empty()){
        return ret;
    }
    int index = 0;
    while(index + 1 < (int)prices.size()){
        if(prices[index+1] >= prices[index]){
            ret += prices[index+1] - prices[index];
        }
        index++;
    }
    return ret;
}