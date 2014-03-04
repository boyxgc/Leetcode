class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //isB[i] = OR{isB[j]}, where 0 < j <= i, and s[j:i] is in dict
        vector<bool> isB(s.size(), false);
        if(dict.find(s) != dict.end()) return true;
        for(int i = 0; i < s.size(); ++i){
            if(dict.find(s.substr(0,i+1)) != dict.end()){
                isB[i] = true;
            } else{
                bool flag = false;
                for(int j = i; j > 0 &&!flag; --j){
                    if(dict.find(s.substr(j,i-j+1)) != dict.end()){
                        flag = isB[j-1];
                    }
                }
                isB[i] = flag;
            }
        }
        return isB[s.size()-1];
    }
};