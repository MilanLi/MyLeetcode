// Edit Distance

// Dynamic programming used.

int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    if(len1 == 0){
        return len2;
    }
    if(len2 == 0){
        return len1;
    }
    vector<vector<int> > DP(len1+1, vector<int>(len2+1, 0));
    for(int i = 1; i <= len1; i++){
        DP[i][0] = i;
    }
    for(int j = 1; j <= len2; j++){
        DP[0][j] = j;
    }
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            //add a char to be the same; detele a char from A is the same as adding a char from B
            DP[i][j] = min(DP[i-1][j]+1, DP[i][j-1]+1); 
            if(word1[i-1] == word2[j-1]){
                DP[i][j] = min(DP[i-1][j-1], DP[i][j]); //if the last char is the same then we are done.
            }
            else{
                DP[i][j] = min(DP[i-1][j-1]+1, DP[i][j]); //if the last char is not the same, we just substitute.
            }
        }
    }
    return DP[len1][len2];
}