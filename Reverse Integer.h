class Solution {
public:
    int reverse(int x) {
        int org = x, rev = 0;
        if(x < 0) 
            org = -x;
        while(org > 0) {
            int q = org % 10;
            org = org /10;
            
            rev = rev * 10 + q;
        }
        if(x < 0)
            rev = -rev;
        return rev;
    }
};