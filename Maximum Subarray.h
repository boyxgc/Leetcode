class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0)
            return 0;
            
        int maxsofar = 0;
        int tmpsum = 0;
        int pos = 0;
        
        while(pos < n) {
            tmpsum += A[pos];
            if(tmpsum < 0 ) {
                tmpsum = 0;
            }
            if(tmpsum > maxsofar) {
                maxsofar = tmpsum;
            }
            pos++;
        }
        
        if(maxsofar == 0) {
            maxsofar = A[0];
            for(int i = 0; i < n; ++i)
                if(A[i] > maxsofar) 
                    maxsofar = A[i];
        }
        
        return maxsofar;
    }
};