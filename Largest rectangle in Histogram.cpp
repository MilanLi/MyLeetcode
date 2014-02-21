// Largest rectangle in Histogram


int largestRectangleArea(vector<int> &height) {
    int area = 0;
    int n = height.size();
    if(n == 0){
        return area;
    }
    stack<int> stk;
    for(int i = 0; i < n; i++){
        if(stk.empty() || height[i] >= height[stk.top()]){
            stk.push(i);
        }
        else{
            while(!stk.empty() && height[stk.top()] >= height[i]){
                int hind = stk.top();
                stk.pop();
                if(stk.empty()){
                    area = max(area, i*height[hind]);
                }
                else{
                    area = max(area, (i-1-stk.top()) * height[hind]);
                }
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        int hind = stk.top();
        stk.pop();
        if(stk.empty()){
            area = max(area, n*height[hind]);
        }
        else{
            area = max(area, (n-1-stk.top())*height[hind]);
        }
    }
    return area;
}