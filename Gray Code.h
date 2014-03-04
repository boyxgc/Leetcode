class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int mask = 1;
        for(int i = 0; i < pow(2,n); ++i){
            //convert to gray : gray(i) = binary(i) xor binary(i+1)
           res.push_back(i^(i >> 1));
        }
        return res;
    }
};