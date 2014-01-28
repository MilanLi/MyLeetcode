// Add Binary


char addtwo(char aa, char bb, char& carry){
    int res = int(aa-'0') + int(bb-'0') + int(carry-'0');
    switch(res){
        case 0: return '0';
        case 1: carry = '0';
                return '1';
        case 2: carry = '1';
                return '0';
        case 3: carry = '1';
                return '1';
    }
}

string addBinary(string a, string b) {
    int sza = a.size();
    int szb = b.size();
    if(sza == 0){
        return b;
    }
    if(szb == 0){
        return a;
    }
    int sz = max(sza, szb);
    string ret(sz+1, '0');
    char carry = '0';
    while(sza > 0 && szb > 0){
        char aa = a[sza-1];
        char bb = b[szb-1];
        ret[sz] = addtwo(aa, bb, carry);
        sza--;
        szb--;
        sz--;
    }
    if(sza == 0 && szb != 0){
        while(szb > 0){
            char bb = b[szb-1];
            ret[sz] = addtwo('0', bb, carry);
            szb--;
            sz--;
        }
    }
    else if(sza != 0 && szb == 0){
        while(sza > 0){
            char aa = a[sza-1];
            ret[sz] = addtwo('0', aa, carry);
            sza--;
            sz--;
        }
    }
    if(carry == '0'){
        return string(ret.begin()+1, ret.end());
    }
    else{
        ret[sz] = carry;
    }
    return ret;
}