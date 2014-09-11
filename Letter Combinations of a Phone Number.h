class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string empty;
        vector<string> res;
        
        generateCombinations(digits, 0, empty, res);
        
        return res;
    }
    
private:
    void generateCombinations(string &digits, int pos, string &curr, vector<string> &res) {
        if(pos == digits.size()) {
            string copy = curr;
            res.push_back(copy);
            return;
        }
        
        string chars = decode(digits[pos]);
        
        for(int i = 0; i < chars.size(); ++i) {
            curr.push_back(chars[i]);
            generateCombinations(digits, pos + 1, curr, res);
            curr.pop_back();
        }
    }

    string decode(char c) {
        switch(c) {
            case '2' : return "abc";
            case '3' : return "def";
            case '4' : return "ghi";
            case '5' : return "jkl";
            case '6' : return "mno";
            case '7' : return "pqrs";
            case '8' : return "tuv";
            case '9' : return "wxyz";
            default : return "";
        }
    }
};