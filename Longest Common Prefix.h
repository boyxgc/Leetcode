class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
        int pos = 0;
        string prefix = "";
        bool goon = true;
        while(goon && pos < strs[0].length()) {
            char tmp = strs[0][pos];
            for(int i = 0; i < strs.size(); ++i) {
                if(pos >= strs[i].size() || strs[i][pos] != tmp){
                    goon = false;
                    break;
                }
            }
            if(goon) {
                stringstream ss;
                string tmpstr;
                ss << tmp;
                ss >> tmpstr;
                prefix += tmpstr;
                pos++;
            }
        }
        return prefix;
    }
};