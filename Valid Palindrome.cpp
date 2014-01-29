// Valid Palindrome


//first parse the string
//then check if the nth element is the same as nth element from right hand side

bool isPalindrome(string s) {
    int sz = s.length();
    if(sz == 0){
        return true;
    }
    int index = 0;
    for(int i = 0; i < sz; ++i){
        if(isalnum(s[i])){
            if(s[i] <='Z' && s[i] >= 'A'){
                s[index++] = tolower(s[i]);
            }
            else{
                s[index++] = s[i];
            }
        }
    }
    s = s.substr(0, index);
    for(int i = 0; i < index/2; i++){
        if(s[i] != s[index-i-1]){
            return false;
        }
    }
    return true;
}