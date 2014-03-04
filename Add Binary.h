class Solution {
public:
    string addBinary(string a, string b) {
        string c ="";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i = 0;
        int carry = 0;
        while(i < a.size() && i < b.size()) {
            int tmp = carry + a[i]-'0'+b[i]-'0';
            carry = tmp/2;
            stringstream ss;
            ss << tmp%2;
            c += ss.str();
            i++;
        }
        while(i < a.size()) {
            int tmp = carry + a[i]-'0';
            carry = tmp/2;
            stringstream ss;
            ss << tmp%2;
            c += ss.str();
            i++;
        }
        while(i < b.size()) {
            int tmp = carry +b[i]-'0';
            carry = tmp/2;
            stringstream ss;
            ss << tmp%2;
            c += ss.str();
            i++;
        }
        if(carry){
            c += "1";
        }
        reverse(c.begin(), c.end());
        return c;
    }
};