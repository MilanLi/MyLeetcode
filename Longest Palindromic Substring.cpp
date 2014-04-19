// Longest Palindromic Substring

public String longestPalindrome(String s) {
    int len = s.length();
    int[][] DP = new int[len][len];
    // length = 1
    for(int i = 0; i < len; i++){
        DP[i][i] = 1;
    }
    // length = 2
    for(int i = 0; i < len-1; i++){
        if(s.charAt(i) == s.charAt(i+1)){
            DP[i][i+1] = 2;
        }
    }
    
    // length > 2
    for(int l = 3; l <= len; l++){
        for(int i = 0; i <= len-l; i++){
            int j = i + l -1;
            if(s.charAt(i) == s.charAt(j) && DP[i+1][j-1] != 0){
                DP[i][j] = DP[i+1][j-1]+2;
            }
        }
    }
    
    //find the longest one
    int longest = 0;
    int start = 0;
    int end = 0;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(DP[i][j] > longest){
              longest = DP[i][j];
                start = i;
                end = j;
            }
        }
    }
    return s.substring(start, end+1);
    
}


//O(n2) time and O(n2) space dynamic programming

string longestPalindromeDP(string s) {
  int n = s.length();
  int longestBegin = 0;
  int maxLen = 1;
  bool table[1000][1000] = {false};
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  return s.substr(longestBegin, maxLen);
}


//O(n2) time and O(1) space

string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}