class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1)
            return n;
            
        int pos1 = 0;
        int pos2 = 1;
        
        while(pos2 < n) {
            while(pos2 < n && A[pos2] == A[pos1]) {
                pos2++;
            }
            if(pos2 < n) {
                pos1++;
                A[pos1] = A[pos2];
                pos2++;
            }
        }
        return pos1+1;
    }
};