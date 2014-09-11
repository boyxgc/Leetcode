class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        if(S.size() == 0) return res;
        
        sort(S.begin(), S.end());
        vector<int> emptyset;
        generateSubsets(S, 0, emptyset, res);
        
        return res;
    }
    
private:
    void generateSubsets(vector<int> & S, int pos, vector<int> curr, vector<vector<int> > &res) {
        res.push_back(curr);
        
        int prev = S[pos] - 1; // just need some number not equal to S[pos]
        for(int i = pos; i < S.size(); ++i) {
            if(S[i] == prev) continue;
            curr.push_back(S[i]);
            generateSubsets(S, i + 1, curr, res);
            curr.pop_back();
            
            prev = S[i];
        }
    }
};