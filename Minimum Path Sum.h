class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> uprow;
        uprow.push_back(grid[0][0]);
        for(int i = 1; i < n; ++i) {
            uprow.push_back(uprow[i-1] + grid[0][i]);
        }
        
        for(int row = 1; row < m; ++row) {
            uprow[0] = uprow[0] + grid[row][0];
            for(int col = 1; col < n; ++col) {
                uprow[col] = min(uprow[col - 1], uprow[col]) + grid[row][col];
            }
        }
        
        return uprow[n-1];
    }
};