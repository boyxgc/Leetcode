class Solution {
public:
    vector<long long> bm_row;
    vector<long long> bm_col;
    vector<long long> bm_squ;
    
    bool solver(vector<vector<char> > &board, int i, int j) {
        int size = board.size();
        if(i >= size || j >= size){
            return true;
        }
            
        if(board[i][j] != '.'){
            if(j+1 >= size){
                j = 0;
                i++;
            } else{
                j++;
            }
            return solver(board, i, j);
        } else {
            bool flag = false;
            for(char num = '1'; num <= '9'; ++num){
                int tmpbm = 1 << (num-'0');
                if((tmpbm & bm_row[i]) || (tmpbm & bm_col[j])|| (tmpbm & bm_squ[(i/3)*3+j/3]))
                    continue;
                flag = true;
                board[i][j] = num;
                bm_row[i] = bm_row[i] | tmpbm;
                bm_col[j] = bm_col[j] | tmpbm;
                bm_squ[(i/3)*3+j/3] = bm_squ[(i/3)*3+j/3] | tmpbm;
                int new_i = i;
                int new_j = j;
                if(new_j+1 >= size){
                    new_j = 0;
                    new_i++;
                } else{
                    new_j++;
                }
                bool succeed = solver(board, new_i, new_j);
                if(succeed)
                    return true;
                board[i][j] = '.';
                bm_row[i] = bm_row[i] &(~tmpbm);
                bm_col[j] = bm_col[j] &(~tmpbm);
                bm_squ[(i/3)*3+j/3] = bm_squ[(i/3)*3+j/3] &(~tmpbm);
            }
            if(!flag)
                return false;
        }
    }

    void solveSudoku(vector<vector<char> > &board) {
        int size = board.size();
        if(size == 0)
            return;
    
        bm_row = vector<long long>(9,0);
        bm_col = vector<long long>(9,0);
        bm_squ = vector<long long>(9,0);
        
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                bm_row[i] = bm_row[i] | (1<<num);
                bm_col[j] = bm_col[j] | (1<<num);
                bm_squ[(i/3)*3+j/3] = bm_squ[(i/3)*3+j/3] | (1<<num);
            }
        }
        solver(board, 0, 0);
        return;
    }
};