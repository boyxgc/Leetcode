class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size() <= 0)
            return digits;
            
        vector<int> res;
        int pos = digits.size() - 1;
        int carry = 1;
        while(pos >= 0 && digits[pos] + carry > 9) {
            digits[pos] = digits[pos] + carry - 10;
            pos--;
        }
        if(pos >= 0){
            digits[pos] += carry;
        } else {
            res.push_back(1);
        }
        for(int i = 0; i < digits.size(); ++i) 
            res.push_back(digits[i]);
            
        return res;
    }
};