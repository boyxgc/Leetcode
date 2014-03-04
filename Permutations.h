class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        res.push_back(num);
        perm(num, 0, res);
        
        return res;
    }
    
    void perm(vector<int> &num, int swap1, vector<vector<int> > &res) {
        if(swap1 == num.size())
            return;
        //res.push_back(tmpv);
        perm(num, swap1+1, res);
        for(int i = swap1; i < num.size(); ++i) {
            if(num[i] != num[swap1]) {
                int tmpi;
                vector<int> tmpv(num);
                tmpi = tmpv[i];
                tmpv[i] = tmpv[swap1];
                tmpv[swap1] = tmpi;
                res.push_back(tmpv);
                perm(tmpv, swap1+1, res);
            }
        }
    }
};