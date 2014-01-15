// Pascal's Triangle II


vector<int> getRow(int rowIndex) {
    vector<int> ret;
    if(rowIndex == 0){
        ret.push_back(1);
        return ret;
    }
    ret.resize(rowIndex + 1);
    ret[rowIndex] = 1;
    int index = 1;
    while(index <= rowIndex){
        ret[rowIndex - index] = 1;
        for(int i = rowIndex - index + 1; i < rowIndex; i++){
            ret[i] += ret[i+1];
        }
        index++;
    }
    return ret;
}