class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0)
            return 0;
        int rows = triangle.size();
        vector<int> lastmin(rows, 0);
        vector<int> curr(rows, INT_MAX);
        lastmin[0] = triangle[0][0];
        
        int ret = INT_MAX;
        for(int i = 1; i < rows; ++i){// starting form 2nd row
            for(int j = 0; j < i; ++j){
                curr[j] = min(curr[j], lastmin[j]+triangle[i][j]);
                curr[j+1] = min(curr[j+1], lastmin[j]+triangle[i][j+1]);
            }
            
            for(int j = 0; j <= i; ++j){
                lastmin[j] = curr[j];
                curr[j] = INT_MAX;
            }
        }
        for(int i = 0; i < rows; ++i){
            if(lastmin[i] < ret){
                ret = lastmin[i];
            }
        }
        return ret;
        
    }
};