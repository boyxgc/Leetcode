class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        
        vector<int> lss(s.size(), 1);
        int lastshow[26];// track each alphabet's last show
        memset(lastshow, -1, 26*sizeof(int));
        
        lastshow[s[0]-'a'] = 0;
        int maxsofar = 1;
        for(int i = 1; i < s.size(); ++i) {
        
            lss[i] = min(i-lastshow[s[i]-'a'], lss[i-1]+1);// reccur function
            lastshow[s[i]-'a'] = i;
            
            if(lss[i] > maxsofar){
                maxsofar = lss[i];
            }
        }
        return maxsofar;
    }
};