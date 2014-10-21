class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";
        string common = strs[0];
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i].size() < common.size()) {
                common = strs[i];
            }
        }
        
        for(int i = 0; i < strs.size(); ++i) {
            string curr = strs[i];
            for(int j = 0; j < curr.size() && j < common.size(); ++j) {
                if(curr[j] != common[j]) {
                    common = common.substr(0, j);
                    break;
                }
            }
            if(common.empty()) return common;
        }
        
        return common;
    }
};