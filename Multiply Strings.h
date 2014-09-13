class Solution {
public:
    string multiply(string num1, string num2) {
        string multiplier;
        string multiplicand;
        
        if(num1.size() > num2.size()) {
            multiplier = num1;
            multiplicand = num2;
        } else {
            multiplier = num2;
            multiplicand = num1;
        }
        
        vector<string> cache(10, "");

        string res = "0";
        string zeros = "";
        for(int i = multiplier.size()-1; i >= 0; --i) {
            int digit = toDigit(multiplier[i]);
            string tmp;
            if(cache[digit] == "") {
                tmp = multiplyWithOneDigit(multiplicand, digit);
                cache[digit] = tmp;
            } else {
                tmp = cache[digit];
            }
            
            if(tmp != "0") tmp += zeros;
            res = addStr(res, tmp);
            zeros += "0";
        }
        return res;
    }
    
    string multiplyWithOneDigit(string str, int num) {
        if(num == 0) return "0";
        if(num == 1) return str;
        
        reverse(str.begin(), str.end());
        string res = "";
        int carry = 0;
        for(int i = 0; i < str.size(); ++i) {
            int curr = toDigit(str[i]);
            int tot = curr * num + carry;
            
            res += to_string(tot%10);
            carry = tot/10;
        }
        if(carry) {
            res += to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    string addStr(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string sum = "";
        
        int p1 = 0, p2 = 0;
        int carry = 0;
        while(p1 < num1.size() || p2 < num2.size()) {
            int tmp = carry;
            if(p1 < num1.size()) {
                tmp += toDigit(num1[p1]);
                p1++;
            }
            if(p2 < num2.size()) {
                tmp += toDigit(num2[p2]);
                p2++;
            }
            
            sum += to_string(tmp%10);
            carry = tmp/10;
        }
        if(carry) {
            sum += to_string(carry);
        }
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
    
    int toDigit(char c) {
        return c - '0';
    }
};