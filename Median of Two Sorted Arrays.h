class Solution {
public:
    double findM(int A[], int m, int B[], int n, int pos){
        if( m > n)
            return findM(B, n, A, m, pos);
        if(m == 0)
            return B[pos-1];
        if(pos == 1){
            return min(A[0], B[0]);
        }
        int k = min(pos/2, m);
        if(A[k-1] < B[k-1]){
            return findM(A+k, m-k, B, n, pos-k);
        } else {
            return findM(A, m, B+k, n-k, pos-k);
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2){
            return findM(A, m, B, n, (m+n)/2+1);
        } else {
            return (findM(A, m, B, n, (m+n)/2+1) + findM(A, m, B, n, (m+n)/2))/2;
        }
    }
};