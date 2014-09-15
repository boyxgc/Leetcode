class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(s.size() == 0) return vector<string>();
        unordered_map<string, vector<string> > cache;
        return wordBreak(s, cache, dict);
    }
    
    vector<string> wordBreak(string str, unordered_map<string, vector<string> > &cache, unordered_set<string> &dict) {
        if(str.size() == 0) {
            vector<string> v;
            v.push_back("");
            return v;
        }
        
        if(cache.find(str) != cache.end()) return cache[str];
        
        vector<string> res;
        for(int len = 1; len <= str.size(); ++len) {
            string word = str.substr(0, len);
            if(dict.find(word) == dict.end()) continue;
            
            vector<string> nextbreak = wordBreak(str.substr(len), cache, dict);
            for(int i = 0; i < nextbreak.size(); ++i) {
                string tmp = nextbreak[i] == "" ? word : word+" "+nextbreak[i];
                res.push_back(tmp);
            }
        }
        
        cache[str] = res;
        return res;
    }
};

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