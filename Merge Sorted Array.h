class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> A2(m, 0);
        for(int i = 0; i < m; ++i) 
            A2[i] = A[i];
            
        int pos = 0;
        int pos1 = 0;
        int pos2 = 0;
        
        while(pos1 < m && pos2 < n) {
            if(A2[pos1] < B[pos2])
                A[pos++] = A2[pos1++];
            else
                A[pos++] = B[pos2++];
        } 
        while(pos1 < m) {
            A[pos++] = A2[pos1++];
        }
        while(pos2 < n) {
            A[pos++] = B[pos2++];
        }
    }
};