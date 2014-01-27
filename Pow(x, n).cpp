// Pow(x, n)

//the range of int is from -2147483648 to 2147483647


double pow(double x, int n) {
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        double num = pow(abs(x), n/2);
        return num*num;
    }
    else if(n > 0){
        double num = pow(abs(x), n/2);
        return num*num*x;
    }
    else{
        double num = pow(abs(x), n/2);
        return num*num/x;
    }
    
}