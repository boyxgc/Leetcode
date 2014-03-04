class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size() == 0)
            return false;
        vector<vector<bool> >visited(board.size(), vector<bool>(board[0].size(), false));
        bool flag;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j) {
                flag = false;
                flag = search(board, word, i, j, 0, visited); 
                visited[i][j] = false;
                if(flag)
                    return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &boards, string word, int i, int j, int pos, vector<vector<bool> > &visited){
        if(boards[i][j] != word[pos])
            return false;
        if(pos == word.size()-1)
            return true;
            
        visited[i][j] = true;
        bool flag = false;
        if( i - 1 >= 0 && !visited[i-1][j]){
            flag = search(boards, word, i-1, j, pos+1, visited);
            if(flag)
                return true;
            visited[i-1][j] = false;
        }
        if(j-1 >= 0 && !visited[i][j-1]){
            flag = search(boards, word, i, j-1, pos+1, visited);
            if(flag)
                return true;
            visited[i][j-1] = false;
        }
        if(i+1 < boards.size() && !visited[i+1][j]){
            flag = search(boards, word, i+1, j, pos+1, visited);
            if(flag)
                return true;
            visited[i+1][j] = false;
        }
        if(j+1 < boards[0].size() && !visited[i][j+1]) {
            flag = search(boards, word, i, j+1, pos+1, visited);
            if(flag)
                return true;
            visited[i][j+1] = false;
        }
        return false;
    }
};