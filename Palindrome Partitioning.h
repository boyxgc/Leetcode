class Solution {
public:
    bool isPal(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s==""){
            return ret;
        }
        if(isPal(s)){
            vector<string> tmp;
            tmp.push_back(s);
            ret.push_back(tmp);
        }
            
        for(int k = 1; k < s.size(); ++k) {
            vector<vector<string> >right;
            if (!isPal(s.substr(0, k))) 
                continue;
            right = partition(s.substr(k));
            for(int i = 0; i < right.size(); ++i){
                right[i].insert(right[i].begin(), s.substr(0, k));
                ret.push_back(right[i]);
            }
        }
        return ret;
    }
};