/*class Solution {
public:
    vector<vector<string> > res;
    //vector<bool> rows;
    vector<bool> cols;
    vector<bool> dagl;
    vector<bool> dagr;
    vector<string> board;
    
    void solve(int row, int n) {
        if(row == n){
            res.push_back(board);
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
    vector<vector<string> > solveNQueens(int n) {
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
        solve(0, n);
        return res;
    }
};*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string> > res;
        
        solve(board, 0, 0, 0, 0, res);
        
        return res;
    }
    
private:
    void solve(vector<string> &board, int row, int col, int diagl, int diagr, vector<vector<string> > &res) {
        if(row == board.size()) {
            vector<string> copy(board);
            res.push_back(copy);
            return;
        }
        
        int available = ~(col | diagl | diagr);
        for(int i = 0; i < board.size(); ++i) {
            int pos = 1 << i;
            if( pos & available) {
                board[row][i] = 'Q';
                solve(board, row + 1, col | pos, (diagl | pos) >> 1, (diagr | pos) << 1, res);
                board[row][i] = '.';
            }
        }
    }
};