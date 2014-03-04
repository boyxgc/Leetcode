class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool flag[10];
        int size = board.size();
        //check row
        for(int i = 0; i < size; ++i) {
            memset(flag, false, 10);
            for(int j = 0; j < size; ++j) {
                char c = board[i][j];
                if(c != '.'){
                    if(flag[c-'0'])
                        return false;
                    flag[c-'0'] = true;
                }
            }
        }
        //check col
        for(int i = 0; i < size; ++i) {
            memset(flag, false, 10);
            for(int j = 0; j < size; ++j) {
                char c = board[j][i];
                if(c != '.'){
                    if(flag[c-'0'])
                        return false;
                    flag[c-'0'] = true;
                }
            }
        }
        //check box
        for(int i = 0; i < size/3; ++i) {
            for(int j = 0; j < size/3; ++j) {
                memset(flag, false, 10);
                for(int k = 0; k < 3; ++k) {
                    for(int l = 0; l < 3; ++l) {
                        char c = board[i*3+k][j*3+l];
                        if(c != '.'){
                            if(flag[c-'0'])
                                return false;
                            flag[c-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};