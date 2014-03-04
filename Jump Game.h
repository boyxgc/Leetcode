class Solution {
public:
    bool canJump(int A[], int n) {
        vector<bool> matrix(n, false);
        matrix[0] = true;
        int maxreach = 0;
        for(int i = 0; i < n; ++i) {
            if(matrix[i]) {
                for(int j = maxreach+1; j <= i+A[i] && j < n; ++j)
                    matrix[j] = true;
                if(i+A[i] > maxreach)
                    maxreach = i+A[i];
            }
        }
        
        return matrix[n-1];
    }
    
};