class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, h = num.size()-1;
        
        while(l < h) {
            int m = l + (h-l)/2;
            if(num[l] < num[h] ) {
                // 1 2 3 4 5 6 7
                if(num[m] >= num[l]) {// min on left
                    h = m - 1;
                } 
                // 6 5 4 3 2 1 7
                else {
                    l = m;
                }
            } else {
                // 7 6 5 4 3 2 1
                if(num[m] > num[h]) {// min on right
                    l = m + 1;
                }
                // 7 1 2 3 4 5 6
                else {
                    h = m;
                }
            }
        }
        
        return num[l];
    }
};