class Solution {
public:
    int trap(int A[], int n) {
        vector<int> maxLeft(n, 0);
        int res = 0;
        int maxL = 0;
        for(int i = 0; i < n; ++i) {
            if(A[i] > maxL)
                maxL = A[i];
            maxLeft[i] = maxL;
        }
        int maxR = 0;
        for(int i = n-1; i >= 0; --i) {
            if(A[i] > maxR)
                maxR = A[i];
            
            res += min(maxLeft[i], maxR) - A[i];
        }
        return res;
    }
};