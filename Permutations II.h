class Solution {
public:
    void swap(int i, int j, vector<int> &num){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    void permute(vector<int> num, int pos, vector<vector<int> > &res) {
        if(pos >= num.size())
            return;
        permute(num, pos+1, res);
        int lastswap = num[pos];
        for(int i = pos+1; i < num.size(); ++i){
            if(num[i] == lastswap) continue;
            lastswap = num[i];

            num.erase(num.begin()+i);
            num.insert(num.begin()+pos, lastswap);
            res.push_back(num);
            permute(num, pos+1, res);
            num.erase(num.begin()+pos);
            num.insert(num.begin()+i, lastswap);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        
        vector<vector<int> > ret;
        ret.push_back(num);
        permute(num, 0, ret);
        return ret;
    }
};