class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string sum = "";
        int carry = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            
            int tot = carry;
            if(i < a.size()) tot += a[i] - '0';
            if(i < b.size()) tot += b[i] - '0';
            
            sum += to_string(tot % 2);
            carry = tot / 2;
        }
        if(carry) {
            sum += to_string(carry);
        }
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};