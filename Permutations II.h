class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        generatePermutations(num, 0, res);
        
        return res;
    }
private:
    void generatePermutations(vector<int> &num, int pos, vector<vector<int> > &res) {
        if(pos == num.size()-1) {
            vector<int> copy(num);
            res.push_back(copy);
            return;
        }
        
        int prev = num[pos] -1;//not equal to num[pos]
        for(int i = pos; i < num.size(); ++i) {
            if(num[i] == prev) continue;
            prev = num[i];
            move(i, pos, num); // cannot use swap here, bacause swap will break the order of numbers
            generatePermutations(num, pos+1, res);
            move(pos, i, num);
        }
    }
    
    void move(int from, int to, vector<int> &num) {
        int tmp = num[from];
        num.erase(num.begin()+from);
        num.insert(num.begin()+to, tmp);
    }
};