// Two Sum


vector<int> twoSum(vector<int> &numbers, int target) {  
    map<int, int> mapping;  
    vector<int> result;  
    for(int i =0; i< numbers.size(); i++){  
        mapping[numbers[i]]=i;  
    }  
    for(int i =0; i< numbers.size(); i++){  
        int searched = target - numbers[i];  
        if(mapping.find(searched) != mapping.end()){  
            result.push_back(i+);  
            result.push_back(mapping[searched]+);  
            break;  
        }  
    }  
    return result;  
}
