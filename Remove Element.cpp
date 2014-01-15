// Remove Element 


int removeElement(int A[], int n, int elem) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n == 0){
        return 0;
    }
    int i = 0;
    int index = 0;
    int upper = n;
    while(i < upper){
        if(A[i] == elem){
            n--;
        }
        else{
            A[index] = A[i];
            index++;    
        }
        i++;
    }
    return n;
}