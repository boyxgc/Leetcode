class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        
        vector<vector<int> >res;
        vector<int> tmpres;
        sub(S, res, tmpres, -1);
        return res;
    }
    
    void sub(vector<int> &S, vector<vector<int> > &res, vector<int> tmpres, int pos) {
        if(pos >= 0)
            tmpres.push_back(S[pos]);
        res.push_back(tmpres);
        
        for(int i = pos+1; i < S.size(); ++i) {
            sub(S, res, tmpres, i);
        }
    }
};