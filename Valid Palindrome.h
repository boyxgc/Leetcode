class Solution {
public:
    char toCap(char c){
        if(c >= 'a' && c <= 'z')
            return c+'A'-'a';
        return c;
    }
    char isAlphaNum(char c){
        return (c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >='0' && c<='9');
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int l=0;
        int r=n-1;
        while(l <= r){
            if(!isAlphaNum(s[l])){
                l++;
                continue;
            }
            if(!isAlphaNum(s[r])){
                r--;
                continue;
            }
            if(toCap(s[l]) != toCap(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};