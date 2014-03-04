class Solution {
public:
    bool search(int A[], int n, int target) {
        return bisearch(A, 0, n-1, target);
    }
    
    bool bisearch(int A[], int l, int h, int target) {
        if(l > h)
            return false;
        int m;
        
        m = (l+h)/2;
        if(A[m] == target) return true;
        if(A[l] != A[h]){
            if(A[m] > target){
                if(A[l] > target && A[l] <= A[m])
                    return bisearch(A, m+1, h, target);//l = m+1;
                else
                    return bisearch(A, l, m-1, target);//h = mid-1;
            } else {
                if(A[h] < target && A[h] >= A[m])
                    return bisearch(A, l, m-1, target);//h = mid-1;
                else
                    return bisearch(A,m+1, h, target);//l = mid+1;
            }
        } else {
            return bisearch(A, l, m-1, target) || bisearch(A, m+1, h, target);
        }
    }
};