// Generate Parentheses


//follows the following rules:
//1. if we still have left parenthesize on hand, we could use it
//2. we can't use right parenthesize more than the left parenthesize.

void generateParen(int l_rem, int r_rem, string current, vector<string>& ret){
    if(l_rem == 0 && r_rem == 0){
        ret.push_back(current);
        return;
    }
    if(l_rem == 0){
        generateParen(l_rem, r_rem-1, current+')', ret);
        return;
    }
    if(r_rem < l_rem){
        return;
    }
    generateParen(l_rem-1, r_rem, current+'(', ret);
    generateParen(l_rem, r_rem-1, current+')', ret);
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    generateParen(n, n, "", ret);
    return ret;
}