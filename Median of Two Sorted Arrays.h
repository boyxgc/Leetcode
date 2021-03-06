
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int tot = m+n;
        if(tot%2) {
            return findKthInTwoArrays(A, m, B, n, (m+n+1)/2);
        } else {
            return (findKthInTwoArrays(A, m, B, n, (m+n)/2+1) + findKthInTwoArrays(A, m, B, n, (m+n)/2))/2.0;
        }
    }
    
    double findKthInTwoArrays(int A[], int m, int B[], int n, int k) {
        if(m > n) {
            return findKthInTwoArrays(B, n, A, m, k);
        }
        
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        
        int khalf = min(k/2, m);
        
        if(A[khalf-1] < B[khalf-1]) {
            return findKthInTwoArrays(A+khalf, m-khalf, B, /*n*/min(khalf+1, n), k-khalf); // if k is odd number, need khalf+1
        } else {
            return findKthInTwoArrays(A, /*m*/min(khalf+1, m), B+khalf, n-khalf, k-khalf);
        }
    }
};

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