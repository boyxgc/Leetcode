class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        
        vector<int> tmp(m+1, 0);
        vector<vector<int> > matrix(n+1, tmp);
        
        matrix[0][1] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(obstacleGrid[i-1][j-1] == 1){
                    matrix[i][j] = 0;
                } else {
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                }
            }
        }
        return matrix[n][m];
    }
};