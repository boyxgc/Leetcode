class Solution {
public:
    double pow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == -1) return (n&1) ? -1 : 1;
        
        bool isneg = false;
        if(n < 0) {
            isneg = true;
            n = -n;
        }
        
        double product = 1.0;
        while(n--) {
            product *= x;
            if(product == 0) return 0;
        }
        
        return isneg ? 1.0/product : product;
    }
};