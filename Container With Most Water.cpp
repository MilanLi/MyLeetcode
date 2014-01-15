// Container With Most Water 


int maxArea(vector<int> &height) {
    if(height.size() < 2){
        return 0;
    }
    int left = 0;
    int right = height.size() - 1;
    int water = 0;
    while(right != left){
        water = max(water, (right-left) * min(height[left], height[right]) );
        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return water;
}