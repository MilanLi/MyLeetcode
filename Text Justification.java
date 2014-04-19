// Text Justification

public String emptySlot(int n){
		String slot = "";
		for(int i = 0; i < n; i++){
			slot = slot + " ";
		}
		return slot;
	}
	
public ArrayList<String> fullJustify(String[] words, int L) {
    ArrayList<String> retList = new ArrayList<String>();
    int currLen = 0;
    int ith = 0;
    int lineStart = 0;
    int numOfWords = words.length;
    while(ith < numOfWords || currLen > 0){
    	if(currLen == 0){
    		lineStart = ith;
    		if(words[ith].length() <= L){
            	currLen = words[ith].length();
            	ith++;
            }
    	}
    	if(ith < numOfWords && currLen + words[ith].length()+1 <= L){
        	currLen = currLen + words[ith].length()+1;
        	ith++;
        }
    	else{
    		// pack into retList
    		String line = "";
    		int n = ith-lineStart-1;
    		int slotLen = L - currLen;
    		if(n == 0 || ith == numOfWords){
    			line = line + words[lineStart];
    			for(int j = lineStart+1; j < ith; j++){
        			line = line + " "+ words[j];
        		}
    			line = line + emptySlot(slotLen);
    		}
    		else{
    			int each = slotLen/n;
        		int left = slotLen % n;
        		for(int j = lineStart; j < ith-1; j++){
        			line = line + words[j]+" "+emptySlot(each);
        			if(left > 0){
        				line = line + " ";
        				left--;
        			}
        		}
        		line = line + words[ith-1];
    		}
    		retList.add(line);
    		currLen = 0;
    	}
    }
    
    return retList;
}