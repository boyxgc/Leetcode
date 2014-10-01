class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; ++i) {
            if( A[i]-1 < 0 || A[i]-1 >= n) continue;
            if(A[i] != A[A[i]-1]) {//case [1,1], if no such condition, it will loop forever
                swap(A, i, A[i]-1);
                i--;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(i+1 != A[i]) return i+1;
        }
        
        return n+1;
    }
    
    void swap(int A[], int i, int j) {
        int tmp = A[i];
        A[i]  = A[j];
        A[j] = tmp;
    }
};