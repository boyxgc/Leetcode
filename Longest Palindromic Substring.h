class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        
        string longest = "";
        for(int i = 0; i < s.size() - 1; ++i) {
            string expa = expand(s, i, i);
            if(expa.size() > longest.size()) longest = expa;
            string expa2 = expand(s, i, i+1);
            if(expa2.size() > longest.size()) longest = expa2;
        }
        
        return longest;
    }
    
    string expand(string s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
};