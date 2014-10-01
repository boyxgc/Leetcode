class Solution {
public:
    void sortColors(int A[], int n) {
        int front = 0;
        int back = n - 1;
        
        int i = 0;
        while(i <= back) {
            if(A[i] == 0) {
                A[i++] = A[front];
                A[front++] = 0;
            } else if (A[i] == 2) {
                A[i] = A[back];
                A[back--] = 2;
            } else {
                i++;
            }
        }
        
        return;
    }
};