// Integer to Roman


string intToRoman(int num) {
    int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    string ret = "";
    while(num > 0){
        int times = num/nums[i];
        for(int j = 0; j < times; j++){
            ret = ret + symbols[i];
        }
        num -= times*nums[i];
        i++;
    }
    return ret;
}