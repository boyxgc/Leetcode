class Solution {
public:
    /*
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return -dividend;
            
        bool pos = !((dividend > 0)^(divisor >0));
        
        
        unsigned long long dd = abs((long long) dividend);
        unsigned long long dr = abs((long long) divisor);
        unsigned long long c = 1;
        
        while(dd > dr) {
            dr = dr << 1;
            c = c << 1;
        }
        
        int res = 0;
        while(dd >= abs((long long) divisor)) {
            while(dd >= dr){
                dd -= dr;
                res += c;
            }
            dr = dr >> 1;
            c = c>>1;
        }
        if(pos) 
            return res;
        else
            return -res;
    } */
    unsigned long long mydivide(unsigned long long dividend, unsigned long long divisor, unsigned long long &r){
        if(dividend == 0) {
            r = 0;
            return 0; 
        }
        unsigned long long q = mydivide(dividend >> 1, divisor, r);
        q = q<<1;
        r = r<<1;
        
        if(dividend&1)
            r += 1;
        if(r >= divisor){
            r -= divisor;
            q++;
        }
        return q;
    }
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;
        unsigned long long r = 0;
        bool positive = !((dividend > 0)^(divisor > 0));
        unsigned long long res = mydivide(abs((long long)dividend), abs((long long)divisor), r);
        res = (int) res;
        return positive ? res : -res;
    }
};