class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        vector<int> tmp;
        vector<vector<int> >res;
        combin(candidates, tmp, 0, target, res);
        
        return res;
    }
    
    void combin(vector<int> & candidates, vector<int> curr, int pos, int target, vector<vector<int> > &res) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < candidates[pos]) {
            return;
        }
        
        for(int i = pos; i < candidates.size() && candidates[i] <= target; ++i) {
            vector<int> tmp(curr);
            tmp.push_back(candidates[i]);
            combin(candidates, tmp, i, target-candidates[i], res);
        }
    }
};