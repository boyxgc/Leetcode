class Solution {
public:
    string expandpal(int i, int j, string s){
        while(i >=0 && j< s.size()){
            if(s[i] != s[j]) break;
            i--; 
            j++;
        }
        i++;
        j--;
        if(j >= i)
            return s.substr(i, j-i+1);
        else 
            return "";
    }
    string longestPalindrome(string s) {
        if(s == "") return "";
        string ret = s.substr(0,1);
        
        for(int i = 0; i < s.size(); ++i){
            string pal1 = expandpal(i, i, s);
            string pal2 = expandpal(i, i+1, s);
            
            if(pal1.length() > ret.length())
                ret = pal1;
            if(pal2.length() > ret.length())
                ret = pal2;
        }
        return ret;
    }
};