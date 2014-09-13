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

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_map<string, bool> cache;
        return wordBreak(s, dict, cache);
    }
    
    bool wordBreak(string s, unordered_set<string> &dict, unordered_map<string, bool> &cache) {
        if(s.empty()) return false;
        if(cache.find(s) != cache.end()) return cache[s];
        
        bool res = false;
        if(dict.find(s) != dict.end()) {
            res = true;
        } else {
            for(int len = 1; len < s.length(); ++len) {
                string left = s.substr(0,len);
                string right = s.substr(len);
                
                if(wordBreak(left, dict, cache) && wordBreak(right, dict, cache)) {
                    res = true;
                    break;
                }
            }
        }
        
        cache[s] = res;
        return res;
    }
};