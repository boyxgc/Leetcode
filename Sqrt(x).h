class Solution {
public:
   int sqrt(int x) {
        long long l = 0;
        long long h = x;
        
        while(l <= h) {
            long long m = l + (h-l)/2;
            long long square = m*m;
            if(square == x) return m;
            else if(square < x) l = m+1;
            else h = m - 1;
        }
        
        return h;
    }
};

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