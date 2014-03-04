class Solution {
public:
    vector<vector<int> > generate(int numRows) {
       vector<vector<int> > res;
       for(int i = 1; i <= numRows; ++i) {
           vector<int> v(i, 1);
           res.push_back(v);
       }
       
       for(int i = 2; i < numRows; ++i) {
           for(int j = 1; j < i; ++j) {
               res[i][j] = res[i-1][j-1] + res[i-1][j];
           }
       }
       return res;
    }
};