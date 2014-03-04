class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;
        int i = 0;
        int j = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int direction = 0;
        int deltai = 0;
        int deltaj = 1;
        vector<vector<bool> > flag(m, vector<bool>(n, false));
        for(int count = 0; count < m*n; ++count) {
            res.push_back(matrix[i][j]);
            flag[i][j] = true;
            
            if(i+deltai < 0 || i+deltai >= m 
                || j+deltaj < 0 || j+deltaj >= n
                || flag[i+deltai][j+deltaj]) {
                direction += 1;
                direction %= 4;
            }
            switch(direction) {
                case 0: deltai = 0; deltaj = 1; break;
                case 1: deltai = 1; deltaj = 0; break;
                case 2: deltai = 0; deltaj = -1; break;
                case 3: deltai = -1; deltaj = 0; break;
                default: break;
            }
            i += deltai;
            j += deltaj;
        }
        return res;
    }
};