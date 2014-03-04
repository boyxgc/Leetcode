class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for(int i = 0; i < n; ++i){
            twos |= ones&A[i];
            ones ^= A[i];
            
            xthrees = ~(twos &ones);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};