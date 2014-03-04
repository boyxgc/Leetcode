class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() <= 0)
            return false;
        vector<int> col0;
        for(int i = 0; i < matrix.size(); ++i)
            col0.push_back(matrix[i][0]);
        int row = bi_search(col0, 0, col0.size()-1, target);
        if(col0[row] == target)
            return true;
        if(col0[row] > target)
            row -= 1;
        if(row < 0)
            return false;
        int col = bi_search(matrix[row], 0, matrix[row].size()-1, target);
        
        return matrix[row][col] == target;
    }
    
    int bi_search(vector<int> &v, int l, int h, int target){
        int m = -1;
        while(l <= h) {
            m = (l+h)/2;
            if(target < v[m])
                h = m-1;
            else if(target == v[m]){
                break;
            } else {
                l = m+1;
            }
        }
        return m;
    }
};