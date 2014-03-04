class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> curr_v;
        comb(n, k, curr_v, res);
        return res;
    }
    
    void comb(int n, int k, vector<int> &curr_v, vector<vector<int> > &res) {
        if(k == 0){
            res.push_back(curr_v);
            return;
        }
            
        int curr = 0;
        if(curr_v.size() > 0)
            curr = curr_v.back();
        for(int i = curr + 1; i <= n; ++i) {
            curr_v.push_back(i);
            comb(n, k-1, curr_v, res);
            curr_v.pop_back();
        }
    }
};