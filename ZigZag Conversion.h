class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1)
            return s;
        vector<string> rows(nRows, "");
        int n = nRows*2 -2;
        for(int i = 0; i < s.length(); ++i){
            int curr = i%n;
            if(curr < nRows)
                rows[curr] += s[i];
            else
                rows[n-curr] += s[i];
        }
        string ret ="";
        for(int i = 0; i < nRows; ++i)
            ret += rows[i];
        return ret;
    }
};