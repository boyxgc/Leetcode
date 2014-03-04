class Solution {
public:
    double pow(double x, int n) {
        if(x == 0.0)
            return 0;
        if(x == 1.0)
            return 1;
        if(x == -1)
            return (n&1) ? -1 : 1;
        if(n == 0 && x != 0.0){
            return 1;
        }
        
        double res = 1.0;
        int absn = (n > 0) ? n : -n;
        while((absn--) > 0) {
            res *= x;
            if(res == 0)
                break;
        }
        if(n > 0)
            return res;
        else
            return 1/res;
    }
};