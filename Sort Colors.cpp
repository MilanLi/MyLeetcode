// Sort Colors

//red points where to put if another red appears.
//blue points where to put if another blue appears.
//white is used to traverse the array.


void sortColors(int A[], int n) {
    if(n > 1){
        int red(0), white(0), blue(n-1);
        while(white != blue+1){
            if(A[white] == 0){
                if(white == red){
                    red++;
                    white++;
                }
                else{
                    int temp = A[red];
                    A[red] = A[white];
                    A[white] = temp;
                    red++;
                    white++;
                }
            }
            else if(A[white] == 1){
                white++;
            }
            else{
                while(A[blue] == 2){
                    blue--;
                }
                if(white != blue+1){
                    int temp = A[blue];
                    A[blue] = A[white];
                    A[white] = temp;
                    blue--;
                }
            }
        }
    }
}