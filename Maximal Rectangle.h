class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > ones(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(j == 0){
                    ones[i][j] = matrix[i][j]-'0';
                } else {
                    if(matrix[i][j] == '1')
                        ones[i][j] = ones[i][j-1]+1;
                }
            }
        }
        
        int maxsofar = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(ones[i][j] == 0)
                    continue;
                int h = i;
                int minones = ones[i][j];
                while(h >=0){
                    if(ones[h][j] == 0)
                        break;
                    minones = min(minones, ones[h][j]);
                    maxsofar = max(maxsofar, minones*(i-h+1));
                    h--;
                }
            }
        }
        return maxsofar;
    }
};