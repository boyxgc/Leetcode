class Solution {
public:
    int numDecodings(string s) {
        if(s.length() <= 0)
            return 0;
        vector<int> v(s.size(), 0);
        
        if(s[0] == '0')
            return 0;
        v[0] = 1;
        for(int i = 1; i < s.size(); ++i) {
            int two = (s[i-1]-'0')*10+(s[i]-'0');
            if(two <= 26 && two >= 10) {
                if(s[i] != '0')
                    v[i] = v[i-1];
                
                if(i-2 < 0){
                    v[i] += 1;
                } else {
                    v[i] += v[i-2];
                }
            } else if(two == 0){
                return 0;
            }else{
                
                if(s[i] == '0') {
                    v[i] = 0;
                } else {
                    v[i] = v[i-1];
                }
            }
        }
        return v[s.size()-1];
    }
};