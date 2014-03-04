class Solution {
public:

    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int wordlen = L[0].size();
        int lsize = L.size();
        if(lsize == 0)
            return ret;

        map<string, int> isShown;
        for(int i = 0; i < lsize; ++i) isShown[L[i]] += 1;
        
        for(int i = 0; i+wordlen*lsize-1 < S.size(); ++i) {
            map<string, int> map2;
            bool flag = true;
            for(int j = 0; j < lsize; ++j){
                string word = S.substr(i+j*wordlen, wordlen);
                if(isShown.find(word) == isShown.end()) {flag = false; break;}
                map2[word] += 1;
                if(map2[word] > isShown[word]) {flag = false; break;}
            }
            
            if(flag) ret.push_back(i);
            
        }
        return ret;
    }
};