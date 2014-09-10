class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int end = m + n -1;
        int a = m - 1;
        int b = n - 1;
        
        while(b >= 0) {
            if(a >= 0 && A[a] > B[b]) {
                A[end--] = A[a--];
            } else {
                A[end--] = B[b--];
            }
        }
        return;
    }
};