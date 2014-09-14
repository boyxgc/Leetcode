class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<int> ava(board.size(), 0);
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(search(board, i, j, word, 0, ava)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int i, int j, string word, int pos, vector<int> &ava) {
        if(pos == word.size()) 
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if(board[i][j] != word[pos])
            return false;
        int bm = 1 << j;
        if(~(ava[i]) & bm) { 
            ava[i] |= bm;
            
            if(search(board, i, j+1, word, pos+1, ava)) return true;
            if(search(board, i+1, j, word, pos+1, ava)) return true;
            if(search(board, i-1, j, word, pos+1, ava)) return true;
            if(search(board, i, j-1, word, pos+1, ava)) return true;
            
            ava[i] &= ~bm;
        }
        return false;
    }
};