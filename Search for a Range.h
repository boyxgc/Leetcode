class Solution {
public:
    /*
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if(n == 0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        int l = 0, h = n-1;
        int m;
        while(l <= h) {
            m = (l+h)/2;
            if(A[m] >= target) {
                h = m-1;
            } else {
                l = m+1;
            }
        }
        if(A[l] != target){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else{
            res.push_back(l);
        }
        
        l = 0, h = n-1;
        while(l <= h) {
            m = (l+h)/2;
            if(A[m] > target) {
                h = m-1;
            } else {
                l = m+1;
            }
        }
        
        res.push_back(h);
        
        return res;
    }*/
    int search(int A[], int n, int target) {
        int l = 0; 
        int h = n-1;
        int mid;
        
        while(l <= h){
            mid = (l+h)/2;
            if(A[mid] == target) return mid;
            
            if(A[mid] < target){
                if(A[h] >= A[mid] && A[h] < target)
                    h = mid-1;
                else
                    l = mid+1;
            } else {
                if(A[l] <= A[mid] && A[l] > target)
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        
        return -1;
    }
};