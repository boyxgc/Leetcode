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