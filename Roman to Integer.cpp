// Roman to Integer


int char2int(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int romanToInt(string s) {
    int n = s.length();
    int ret = 0;
    if(n == 0){
        return 0;
    }
    int curr;
    for(int i = 0; i < n; i++){
        curr = char2int(s[i]);
        if(i+1 < n && curr < char2int(s[i+1])){
            ret += curr * -1;
        }
        else{
            ret += curr;
        }
    }
    return ret;
}