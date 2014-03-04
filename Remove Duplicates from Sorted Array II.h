class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int pos = 0;// track new array
        int count = 1;// count each num
        
        for(int i = 1; i < n; ++i){
            if(A[i] == A[pos] && count < 2){
                count++;
                A[++pos] = A[i];
            }
            if(A[i] != A[pos]){
                count = 1;
                A[++pos] = A[i];
            }
        }
        return pos+1;
    }
};