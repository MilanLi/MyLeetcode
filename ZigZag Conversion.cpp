// ZigZag Conversion


string convert(string s, int nRows) {
    int n = s.length();
    if(n <= 1 || nRows <= 1){
        return s;
    }
    string ret = "";
    int interval = 2*(nRows-1);
    int index = 0;
    vector<int> pith;
    while(index < n){
        pith.push_back(index);
        ret += s[index];
        index += interval;
    }
    for(int i = 1; i < nRows; i++){
        index = i;
        if(index >= n){
            break;
        }
        ret += s[index];
        int fint = interval - 2*i;
        int sint = 2*i;
        while(index < n){
            if(fint != 0){
                if(index + fint < n){
                    index += fint;
                    ret += s[index];
                }
                else{
                    break;
                }
            }
            if(index + sint < n){
                index += sint;
                ret += s[index];
            }
            else{
                break;
            }
        }
    }
    return ret;
}