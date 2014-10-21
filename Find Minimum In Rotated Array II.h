class Solution {
public:
    int findMin(vector<int> &num) {
        int m, l = 0, h = num.size()-1;
        while(l < h && num[l] >= num[h]) {
            m = (l+h)/2;
            if(num[m] > num[h]) { // leftside monotonic descending, all are greater than A[h]
                l = m+1;
            } else if(num[m] < num[l]) { // rightside monotonic ascending, all are smaller than A[l]
                h = m;
            } else { // A[l] == A[m] == A[h]
                l = l+1;
            }
        }
        return num[l];
    }
    
    // solution 2
    int findMin2(vector<int> &num, int l, int h) {
        if(h-l < 2) return min(num[l], num[h]);
        
        int m = l+(h-l)/2;
        if(num[m] != num[l]) {
            if(num[m] < num[l] && num[h] <= num[l] || num[m] > num[l] && num[h] > num[l]) {
                h = m;
            } else {
                l = m;
            }
            return findMin(num, l, h);
        } else {
            if(num[m] > num[h]) {
                return findMin(num, m+1, h);
            } else if(num[m] < num[h]) {
                return num[m];
            } else {
                return min(findMin(num, l, m-1), findMin(num, m+1,h));
            }
        }
    }
};