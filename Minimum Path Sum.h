class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> > opt;
        for(int i = 0; i <= n; ++i){// 1 more row and colummn
            vector<int> tmpv(m+1,-1);
            opt.push_back(tmpv);
        }
        
        for(int i = 1; i <= n; ++i){// starts from row 1
            for(int j = 1; j <= m; ++j) {
                int minsofar = -1;
                opt[i][j] = grid[i-1][j-1] + max(0, mymin(minsofar,mymin(opt[i-1][j], opt[i][j-1])));
            }
        }
        
        return opt[n][m];
    }
    
    int mymin(int minsofar, int num) {
        if(minsofar < 0)
            return num;
        if(num < 0)
            return minsofar;
        return min(minsofar, num);
    }
};