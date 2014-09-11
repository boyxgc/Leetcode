class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;
        
        vector<int> prev(triangle.size(), 0);
        vector<int> curr(triangle.size(), 0);
        
        prev[0] = triangle[0][0];
        int rowmin = prev[0];
        for(int i = 1; i < triangle.size(); ++i) {
            curr[0] = prev[0] + triangle[i][0];
            curr[i] = prev[i-1] + triangle[i][i];
            rowmin = min(curr[0], curr[i]);
            for(int j = 1; j < i; ++j) {
                curr[j] = min(prev[j], prev[j-1]) + triangle[i][j];
                if(curr[j] < rowmin) rowmin = curr[j];
            }
            prev.swap(curr);
        }
        return rowmin;
    }
};