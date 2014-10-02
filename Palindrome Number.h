class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int div = 1;
        int tmp = x;
        while(tmp >= 10) {
            div *= 10;
            tmp /= 10;
        }
        
        while(x) { // while(x > 10) is wrong condition, case 100021
            int l = x/div;
            int r = x%10;
            if(l != r) return false;
            x = (x%div)/10;
            div /= 100;
        }
        
        return true;
    }
};

// possibly wrong solution, could overflow, case: 2147483647
public class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
            return false;
        int x1 = x;
        int x2 = 0;
        while(x1/10 > 0) {
            x2 = x2*10 + x1%10;
            x1 = x1/10;
        }
        x2 = x2*10 + x1;
        
        return (x == x2);
    }
}