class Solution {
public:
    int sqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        double a = 1.0;
        double a2;
        while(true){
            a2 = (a+x/a)/2.0;
            if(abs(a2-a) < 1.0) return a2;
            a = a2;
        }
        return a;
    }
};