class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> >opt;
        for(int i = 0; i <=m; ++i){
            vector<int> tmpv(n+1, 0);
            opt.push_back(tmpv);
        }
        opt[1][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i != 1 || j != 1)//skip opt[1][1]
                    opt[i][j] = opt[i-1][j] + opt[i][j-1];
            }
        }
        
        return opt[m][n];
    }
};