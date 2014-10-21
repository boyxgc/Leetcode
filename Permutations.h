class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        generatePermutations(num, 0, res);
        
        return res;
    }
    
private:
    void generatePermutations(vector<int> &curr, int pos, vector<vector<int> > &res) {
        if(pos == curr.size()) {
            res.push_back(curr);
        }
        for(int i = pos; i < curr.size(); ++i) {
            vector<int> newv(curr);
            //newv.erase(newv.begin() + i);
            //newv.insert(newv.begin() + pos, curr[i]);
            newv[pos] = newv[i];// because all the numbers are unique, we don't need to keep the order
            newv[i] = curr[pos];// so swaping is okay here
            generatePermutations(newv, pos+1, res);
            //backtracking, not necesseary
            newv[i] = newv[pos];
            newv[pos] = curr[pos];
        }
    }
};