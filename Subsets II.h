class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> >res;
        vector<int> tmp;
        sub(S, tmp, -1, res);
        
        return res;
        
    }
    
    void sub(vector<int> &S, vector<int> curr, int pos, vector<vector<int> > &res) {
        if(pos >= (int)(S.size()))//S.size() returns unsigned int(wrong when pos is neg)!!! so must cast to int!
            return;
        if(pos >= 0)
            curr.push_back(S[pos]);
        res.push_back(curr);
        
        sub(S, curr, pos+1, res);
        for(int i = pos+2; i < S.size(); ++i) {
            if(!checkdup(S, i)) {
                sub(S, curr, i, res);
            }
        }
    }
    
    bool checkdup(vector<int> &S, int pos) {
        if(pos < 1)
            return false;
        return S[pos-1]==S[pos];
    }
};