class Solution {
public:
    int jump(int A[], int n) {
        
        vector<int> steps(n, INT_MAX);
        steps[0] = 0;
        
        int farthest = 0;
        for(int i = 0; i < n; ++i) {
            int could_cover = i + A[i];
            if(could_cover > farthest) {
                for(int j = farthest+1; j <= could_cover && j < n; j++) {
                    steps[j] = steps[i] + 1;
                }
                farthest = could_cover;
            }
            
            if(farthest == n-1) break;
        }
        
        return steps[n-1];
    }
};