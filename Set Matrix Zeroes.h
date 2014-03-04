class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() <= 0)
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int row1 = row, col1 = col;
        bool flag = true;
        for(int i = 0; (i < row) && flag; ++i){
            for(int j = 0; (j < col) && flag; ++j) {
                if(matrix[i][j] == 0) {
                    row1 = i;
                    col1 = j;
                    flag = false;
                }
            }
        }
        
        if(!flag) {
            for(int i = 0; i < col; ++i) {
                if(matrix[row1][i] == 0)
                    matrix[row1][i] = 1;
                else
                    matrix[row1][i] = 0;
            }
            for(int i = 0; i < row; ++i){
                if(matrix[i][col1] == 0)
                    matrix[i][col1] = 1;
                else
                    matrix[i][col1] = 0;
            }
            matrix[row1][col1] = 1;// mark
        }
        
        //record with row1 and col1
        if(!flag) {
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j) {
                    if(i != row1 && j != col1 && matrix[i][j] == 0) {
                       matrix[row1][j] = 1;
                       matrix[i][col1] = 1;
                    }
                }
            }
        }
        
        //set zero according to row1 and col1
        if(!flag) {
            for(int i = 0; i < col; ++i) {
                if(i != col1 && matrix[row1][i] == 1) {
                    //set col i zero
                    for(int j = 0; j < row; ++j){
                        if(j != row1)
                            matrix[j][i] = 0;
                    }
                } 
            }
            for(int i = 0; i < row; ++i) {
                if(i != row1 && matrix[i][col1] == 1) {
                    //set row i zero
                    for(int j = 0; j < col; j++){
                        if(j != col1)
                            matrix[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < col; ++i)
                matrix[row1][i] = 0;
            for(int i = 0; i < row; ++i)
                matrix[i][col1] = 0;
        }
    }
};