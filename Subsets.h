class Solution {
public:

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> emptyv;
        vector<vector<int> > res;
        generate(S, 0, emptyv, res);
        
        return res;
    }
private:
    void generate(vector<int> &S, int pos, vector<int> curr, vector<vector<int> > & res) {
        res.push_back(curr);
        
        for(int i = pos; i < S.size(); ++i) {
            curr.push_back(S[i]);
            generate(S, i + 1, curr, res);
            curr.pop_back();
        }
    }
};