// Divide Two integers


int divide(int dividend, int divisor) {
    long long dd = abs((long long) dividend);
    long long ds = abs((long long) divisor);
    long long ret = 0;
    while(dd >= ds){
        long long t = ds;
        int i = 1;
        while((t<<1) < dd){
            t = t << 1;
            i = i << 1;
        }
        ret += i;
        dd -= t;
    }
    return ((dividend ^ divisor) >> 31)? (-ret): ret;
}