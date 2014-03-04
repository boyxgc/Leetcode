class Solution {
public:
    void sortColors(int A[], int n) {
        //one pass solution
        //meet 0 put from front, meet 2 put from end
        
        int i = 0;
        int front = 0;
        int back = n-1;
        while(i <= back){
            if(A[i] == 0) {
                if(i > front) {
                    A[i] = A[front];   
                    A[front++] = 0;
                } else{
                    front++;
                    i++;
                }
            }else if(A[i] == 2){
                A[i] = A[back];
                A[back--] = 2;
            }else{
                i++;
            }
        }
    }
};