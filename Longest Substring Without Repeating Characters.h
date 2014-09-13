class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> lastShow(256, -1);
        
        lastShow[s[0]] = 0;
        int max = 1;
        int prevLongest = 1;
        for(int i = 1; i < s.size(); ++i) {
            int currLongest = min(i - lastShow[s[i]], prevLongest+1);
            
            if(currLongest > max) {
                max = currLongest;
            }
            prevLongest = currLongest;
            lastShow[s[i]] = i;
        }
        
        return max;
    }
};