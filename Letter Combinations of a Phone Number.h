class Solution {
public:
    string digit2string(int i) {
        switch(i) {
            case 0: return " ";
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
            default: return "%";
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if(digits == ""){
            res.push_back("");
            return res;
        }
            
        for(int i = 0; i < digits.size(); ++i) {
            string letters = digit2string(digits[i]-'0');
            if(res.size() == 0) {
                for(int p = 0; p < letters.length(); ++p)
                    res.push_back(string(1, letters[p]));
            } else {
                int currsize = res.size();
                for(int j = 0; j < currsize; ++j) {
                    string str = res[j];
                    res[j] = str+letters[0];
                    if(letters.size() > 1) {
                        for(int p = 1; p < letters.length(); ++p)
                            res.push_back(str+letters[p]);
                    }
                }
            }
        }
        
        return res;
    }
};