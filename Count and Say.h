class Solution {
public:
    string convert(string digits){
        string ret = "";
    
        int i = 0;
        char digit = digits[0];
        int count = 0;
        for(int i = 0; i < digits.size(); ++i) {
            if(digits[i] == digit){
                count++;
            }else{
                stringstream ss1;
                ss1 << count;
                ret += ss1.str() + digit;
                count = 1;
                digit = digits[i];
            }
        }
        stringstream ss1;
        stringstream ss2;
        ss1 << count;
        ret += ss1.str() + digit;
        
        return ret;
    }
    string countAndSay(int n) {
        string num = "1";
        while(n-1){
            num = convert(num);
            n--;
        }
        return num;
    }
};