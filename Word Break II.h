class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool> >dictMap(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); ++i){
            for(int j = i; j < s.size(); ++j){
                if(dict.find(s.substr(i, j-i+1)) != dict.end())
                    dictMap[i][j] = true;
            }
        }
        vector<string> ret;
        bool flag = false;
        for(int i = 0; i < s.size()&&!flag; ++i){
            flag = flag || dictMap[i][s.size()-1];
        }
        if(flag)// if the last char is not reachable, then no need to search
            output(s, 0, "", ret, dictMap);
        return ret;
    }
    void output(string s, int pos, string curr, vector<string> &res, vector<vector<bool> > &dictMap){
        if(pos == s.size()){
            curr.pop_back();//del last blank
            res.push_back(curr);
            return;
        }
        for(int i = pos; i < s.size(); ++i) {
            if(dictMap[pos][i]){
                output(s, i+1, curr+s.substr(pos, i-pos+1)+" ", res, dictMap);
            }
        }
    }
};