// Median of Two Sorted Arrays


//find the kth smallest value in the array


int firstK(int* a, int* b, int na, int nb, int k){
    if(na > nb){
        return firstK(b, a, nb, na, k);
    }
	int ma = (na < k / 2) ? na - 1 : k / 2 - 1;
	int mb = k - ma - 2;
	if (na == 0){
		return b[k - 1];
	}
	if (nb == 0){
		return a[k - 1];
	}
	if (k == 1){
		return std::min(a[0], b[0]);
	}
	if (a[ma] < b[mb]){
		return firstK(a + ma + 1, b, na - ma - 1, nb, k - ma - 1);
	}
	else if (a[ma] > b[mb]){
		return firstK(a, b + mb + 1, na, nb - mb - 1, k - mb - 1);
	}
	else{
		return a[ma];
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2 == 0){
		return ((double)firstK(A, B, m, n, (m + n) / 2) + (double)firstK(A, B, m, n, (m + n) / 2 + 1))/2;
	}
	else{
		return firstK(A, B, m, n, (m + n) / 2 + 1);
	}
}