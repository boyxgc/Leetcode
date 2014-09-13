/*class Solution {
public:
    // O(n^3)
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > ones(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(j == 0){
                    ones[i][j] = matrix[i][j]-'0';
                } else {
                    if(matrix[i][j] == '1')
                        ones[i][j] = ones[i][j-1]+1;
                }
            }
        }
        
        int maxsofar = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(ones[i][j] == 0)
                    continue;
                int h = i;
                int minones = ones[i][j];
                while(h >=0){
                    if(ones[h][j] == 0)
                        break;
                    minones = min(minones, ones[h][j]);
                    maxsofar = max(maxsofar, minones*(i-h+1));
                    h--;
                }
            }
        }
        return maxsofar;
    }
}; */

class Solution {
public:
    // O(n^2)
    int maximalRectangle(vector<vector<char> > &matrix) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int maxRect = 0;
        vector<int> histogram(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '0') {
                    histogram[j] = 0;
                } else {
                    histogram[j] += 1;
                }
            }
            
            maxRect = max(maxRect, maxRectangleInHistogram(histogram));
        }
        
        return maxRect;
    }
    
    int maxRectangleInHistogram(vector<int> &rects) {
        if(rects.size() == 0) return 0;
        if(rects.size() == 1) return rects[0];
        
        int size = rects.size();
        vector<int> leftBorder(size, 0);
        for(int i = 0; i < size; ++i) {
            int tmp = i;
            while(tmp -1 >= 0 && rects[tmp-1] >= rects[i]) {
                tmp = leftBorder[tmp-1];
            }
            leftBorder[i] = tmp;
        }
        
        int maxRect = 0;
        vector<int> rightBorder(size, size -1);
        for(int i = size-1; i >= 0; --i) {
            int tmp = i;
            while(tmp+1 < size && rects[tmp+1] >= rects[i]) {
                tmp = rightBorder[tmp+1];
            }
            rightBorder[i] = tmp;
            
            maxRect = max(maxRect, rects[i]*(rightBorder[i] - leftBorder[i] + 1));
        }
        
        return maxRect;
    }
};