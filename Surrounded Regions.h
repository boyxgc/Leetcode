class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int> > q;
        
        for(int i = 0; i < n; ++i) {
            if(board[0][i] == 'O')
                q.push(make_pair(0, i));
            if(board[m-1][i] == 'O')
                q.push(make_pair(m-1, i));
        }
        for(int i = 0; i < m; ++i) {
            if(board[i][0] == 'O')
                q.push(make_pair(i, 0));
            if(board[i][n-1] == 'O')
                q.push(make_pair(i, n-1));
        }
        
        // DFS mark will not pass the big data test!!
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            board[i][j] = 'M';
            
            putIn(q, i-1, j, board);
            putIn(q, i+1, j, board);
            putIn(q, i, j-1, board);
            putIn(q, i, j+1, board);
        }
        
        reMark(board, 'O', 'X');
        reMark(board, 'M', 'O');
    }
    
    void putIn(queue<pair<int,int> >&q, int i, int j, vector<vector<char> > &board) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] == 'O') {
            q.push(make_pair(i, j));
        }
    }
    
    void reMark(vector<vector<char> > &board, char original, char newch) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == original) board[i][j] = newch;
            }
        }
    }
};