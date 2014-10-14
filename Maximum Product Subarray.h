/*
    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        int min_ending_here = 1;
        int max_ending_here = 1;
        int maxsofar = INT_MIN;
        
        for(int i = 0; i < n; ++i) {
            if(A[i] > 0) {
                max_ending_here *= A[i];
                min_ending_here *= A[i];
                maxsofar = max(maxsofar, max_ending_here);
            } else if(A[i] == 0) {
                maxsofar = max(maxsofar, 0);
                max_ending_here = 1;
                min_ending_here = 1;
            } else {
                maxsofar = max(maxsofar, min_ending_here*A[i]);// current max must be min_ending_here*A[i]
                int old_max_ending_here = max_ending_here;
                max_ending_here = max(min_ending_here*A[i], 1);// if min_ending_here is positive, max_ending_here should be back to 1
                min_ending_here = old_max_ending_here*A[i];
            }
        }
        
        return maxsofar;
    }
};