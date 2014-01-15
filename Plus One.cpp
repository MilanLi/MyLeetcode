// Plus One


void plusOne(vector<int> & digits, int add){
    int num = digits[add] + 1;
    if(num == 10){
        digits[add] = 0;
        if(add == 0){
            digits.push_back(1);
            for(int i = digits.size(); i > 0; i--){
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }
        else{
            plusOne(digits, add-1);
        }
    }
    else{
        digits[add] = num;
    }
}

vector<int> plusOne(vector<int> &digits) {
    if(digits.empty()){
        return digits;
    }
    int sz = digits.size();
    plusOne(digits, sz-1);
    return digits;
}