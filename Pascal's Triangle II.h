class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res0;
        if(rowIndex < 0)
            return res0;
        if(rowIndex == 0){
            res0.push_back(1);
            return res0;
        }
        if(rowIndex == 1) {
            res0.push_back(1);
            res0.push_back(1);
            return res0;
        }
        
        vector<int> last(rowIndex+1, 1);
        vector<int> res(rowIndex+1, 1);
        
        for(int i = 2; i <= rowIndex; ++i) {
            for(int j = 1; j < i; ++j) {
                res[j] = last[j-1]+last[j];
            }
            for(int j = 1; j < i; ++j) {
                last[j] = res[j];
            }
        }
        return res;
    }
};