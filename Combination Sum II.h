class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> curr;
        comb(num, 0, ret, curr, target);
        return ret;
    }
    
    void comb(vector<int> & num, int pos, vector<vector<int> > &res, vector<int> curr, int target){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(curr);
        }
        if(pos >= num.size()) return;
        int prev = -1;
        for(int i = pos; i < num.size(); ++i){
            if(num[i] > target)
                break;
            if(num[i] == prev)
                continue;
            prev = num[i];
            vector<int> tmpcurr(curr);
            tmpcurr.push_back(num[i]);
            comb(num, i+1, res, tmpcurr, target-num[i]);
        }
    }
};