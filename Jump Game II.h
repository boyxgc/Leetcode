class Solution {
public:
    int jump(int A[], int n) {
        vector<int> steps(n, n);
        steps[0] = 0;
        int curr_covered = 0;
        for(int i = 0; i < n; ++i){
            if(i+A[i] <= curr_covered)
                continue;
            for(int j = curr_covered+1; j <= A[i]+i && j < n; ++j){
                steps[j] = min(steps[j], steps[i]+1);
            }
            curr_covered = A[i]+i;
        }
        return steps[n-1];
    }
};