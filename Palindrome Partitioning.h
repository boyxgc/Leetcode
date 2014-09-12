class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.empty()) return res;
        
        vector<bool> v(s.size(), false);
        vector<vector<bool> > isPal(s.size(), v);
        
        preprocess(isPal, s); //O(n^2)
        
        vector<string> empty;
        generateParts(s, 0, empty, res, isPal); //O(n^2)
        
        return res;
    }
    
private:
    void generateParts(const string &s, int pos, vector<string> & curr, vector<vector<string> > & res, const vector<vector<bool> > &isPal) {
        if(pos == s.size()) {
            vector<string> copy(curr);
            res.push_back(curr);
            return;
        }
        
        for(int i = pos; i < s.size(); ++i) {
            if(isPal[pos][i]) {
                curr.push_back(s.substr(pos, i - pos + 1));
                generateParts(s, i+1, curr, res, isPal);
                curr.pop_back();
            }
        }
    }

    void preprocess(vector<vector<bool> > &isPal, const string &s) {
        for(int i = 0; i < s.size(); ++i) {
            isPal[i][i] = true;
        }
        for(int len = 2; len <= isPal.size(); ++len) {
            for(int i = 0; i < isPal.size() - len + 1; ++i) {
                int a = i+len - 1;
                if(len < 3) {
                    isPal[i][a] = (s[i] == s[a]);
                } else {
                    isPal[i][a] = (s[i] == s[a]) && isPal[i+1][a-1];
                }
            }
        }
    }
};