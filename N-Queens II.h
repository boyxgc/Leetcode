class Solution {
public:
    /*
    int res;
    //vector<bool> rows;
    vector<bool> cols;
    vector<bool> dagl;
    vector<bool> dagr;
    vector<string> board;
    
    void solve(int row, int n) {
        if(row == n){
            res++;
            return;
        }
        for(int i = 0; i < n; ++i){
            if(cols[i] && dagl[i+row] && dagr[row+n-1-i]) {
                cols[i] = false;
                dagl[i+row] = false;
                dagr[row+n-1-i] = false;
                board[row][i] = 'Q';
                
                solve(row+1, n);
                
                board[row][i] = '.';
                cols[i] = true;
                dagl[i+row] = true;
                dagr[row+n-1-i] = true;
            }
        }
    }
    
    int totalNQueens(int n) {
        for(int i = 0; i < n; ++i){
            //rows.push_back(true);
            cols.push_back(true);
            string str(n, '.');
            board.push_back(str);
        }
        for(int i = 0; i < n*2-1; ++i){
            dagl.push_back(true);
            dagr.push_back(true);
        }
        res = 0;
        solve(0, n);
        return res;    
    }
    */
    
    //bit operation
    int res;
    void solve(int n, int row, int col, int ld, int rd){
        if(row == n){
            res++;
            return;
        }
        int avaliable = ~(col|ld|rd);
        for(int i = 0; i < n; ++i){
            int pos = 1 << i;
            if(pos & avaliable){
                solve(n, row+1, col|pos, (ld|pos) << 1, (rd|pos)>>1);
            }
        }
    }
    
    int totalNQueens(int n) {
        res = 0;
        solve(n, 0, 0, 0, 0);
        return res;
    }
};