// Reverse Integer


int reverse(int x) {
    bool isNeg = (x < 0)? true: false; //check if it is negative value
    x =abs(x);
    
    int ret = 0;
    while(x > 0){
        ret = ret*10 + x % 10;
        x /= 10;
    }
    if(ret < 0){ // indicates overflow
        return -1;
    }
    if(isNeg){ 
        return ret*-1;
    }
    return ret;
}