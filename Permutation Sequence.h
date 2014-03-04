class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n+1,1);
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i)
            factorial[i] = i*factorial[i-1];
        vector<int> digits;
        for(int i = 1; i <= n; ++i)
            digits.push_back(i);
            
        return getP(n, k-1, digits, factorial);
    }
    
    string getP(int n, int k, vector<int> &digits, vector<int> &f){
        if(k == 0 || digits.size() < 2){
            string ret ="";
            for(int i = 0; i < digits.size(); ++i)
                ret += to_string(digits[i]);
            return ret;
        }
        int whichSubTree = k/(f[n-1]);
        string fixed;
        fixed = to_string(digits[whichSubTree]);
        digits.erase(digits.begin()+whichSubTree);
        return fixed + getP(n-1, k%(f[n-1]), digits, f);
    }

};