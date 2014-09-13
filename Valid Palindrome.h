class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.size() - 1;
        while(l < h) {
            if(!isalpha(s[l]) && !isdigit(s[l])) {
                l++;
                continue;
            }
            if(!isalpha(s[h]) && !isdigit(s[h])) {
                h--;
                continue;
            }
            if(toLower(s[l]) != toLower(s[h])) return false;
            l++;
            h--;
        }
        return true;
    }
    
    int toLower(int c) {
        if(isalpha(c)) return tolower(c);
        else return c;
    }
};