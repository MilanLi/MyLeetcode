// Palindrome Partitioning


private boolean[][] constructTable(String s){
	int len = s.length();
	boolean[][] DP = new boolean[len][len];
	
	// length = 1
	for(int i = 0; i < len; i++){
		DP[i][i] = true;
	}
	
	//length = 2
	for(int i = 0; i < len-1; i++){
		if(s.charAt(i) == s.charAt(i+1)){
			DP[i][i+1] = true;
		}
	}
	
	//length > 2
	for(int l = 3; l <= len; l++){
		for(int i = 0; i <= len-l; i++){
			int j = i + l -1;
			if(s.charAt(i) == s.charAt(j)){
				DP[i][j] = DP[i+1][j-1];
			}
		}
	}
	return DP;
	
}

public int minCut(String s) {
    boolean[][] table = constructTable(s);
    int len = s.length();
    int[] DP = new int[len+1];
    for(int end = 1; end <= len; end++){
    	int minVal = len;
    	for(int start = 1; start <= end; start++){
    		if(table[start-1][end-1] == true){
    			minVal = Math.min(minVal, DP[start-1]);
    		}
    	}
    	DP[end] = minVal + 1;
    }
    return DP[len]-1;
}