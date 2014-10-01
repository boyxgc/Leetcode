class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l, h, mid;
        
        l = 0;
        h = m - 1;
        while(l <= h) {
            mid = (l+h)/2;
            int num = matrix[mid][0];
            if(num == target) {
                return true;
            } else if (num > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        int row = h;
        if(row < 0) return false;
        
        l = 0;
        h = n - 1;
        while(l <= h) {
            mid = (l+h)/2;
            int num = matrix[row][mid];
            if(num == target) {
                return true;
            } else if (num > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    
        return false;
    }
};