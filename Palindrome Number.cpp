// Palindrome Number


bool isPalindrome(int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(x < 0){
        return false;
    }
    
    int div = 1;
    while(x / div >= 10){
        div *= 10;
    }
    
    while(x > 0){
        int r = x % 10;
        int l = x / div;
        if(l != r){
            return false;
        }
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}