class Solution {
public:
    void reMark(vector<vector<char> > &board, char c1, char c2){
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == c1)
                    board[i][j] = c2;
            }
        }
    }
    void dfsMark(vector<vector<char> > &board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if(board[i][j] != 'O') return;
        
        board[i][j] = 'M';
        
        dfsMark(board, i-1, j);
        dfsMark(board, i+1, j);
        dfsMark(board, i, j-1);
        dfsMark(board, i, j+1);
    }
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return;
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; ++i){
            if(board[i][0] == 'O')
                dfsMark(board, i, 0);
            if(board[i][col-1] == 'O')
                dfsMark(board, i, col-1);
        }
        for(int i = 0; i < col; ++i){
            if(board[0][i] == 'O')
                dfsMark(board, 0, i);
            if(board[row-1][i] == 'O')
                dfsMark(board, row-1, i);
        }
        reMark(board, 'O', 'X');
        reMark(board, 'M', 'O');
    }
};