class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int n = board.size();
        vector<int> bitmap_row(n+1, 0);
        vector<int> bitmap_col(n+1, 0);
        vector<int> bitmap_squ(n+1, 0);
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                char c = board[i][j];
                if(isdigit(c)) {
                    int num = c - '0';
                    bitmap_row[i] |= 1 << num;
                    bitmap_col[j] |= 1 << num;
                    bitmap_squ[(i/3) * 3+j/3] |= 1 << num;
                }
            }
        }
        
        solve(board, 0, 0, bitmap_row, bitmap_col, bitmap_squ);
        return;
    }
    
    bool solve(vector<vector<char> > &board, int i, int j, vector<int> &bm_row, vector<int> &bm_col, vector<int> &bm_squ) {
        if(i == board.size()) return true;
        if(j >= board.size()) return solve(board, i+1, 0, bm_row, bm_col, bm_squ);
        
        if(board[i][j] != '.') return solve(board, i, j+1, bm_row, bm_col, bm_squ);
        
        for(int num = 1; num < 10; ++num) {
            int pos = 1 << num;
            int available = ~(bm_row[i] | bm_col[j] | bm_squ[(i/3) * 3+j/3]);
            if(pos & available){
                board[i][j] =  '0'+num;
                bm_row[i] |= pos;
                bm_col[j] |= pos;
                bm_squ[(i/3) * 3+j/3] |= pos;
                
                if(solve(board, i, j+1, bm_row, bm_col, bm_squ)) return true;
                
                board[i][j] =  '.';
                bm_row[i] &= ~pos;
                bm_col[j] &= ~pos;
                bm_squ[(i/3) * 3+j/3] &= ~pos;
            }
        }
        
        return false;
    }
};