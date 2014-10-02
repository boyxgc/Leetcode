class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, "", n, res);
        return res;
    }
    
private:
    void generate(int lp, int rp,  string curr, int n, vector<string> & res) {
        if(lp == n && rp == n) {
            res.push_back(curr);
        }
        
        if(rp < lp) {
            generate(lp, rp+1, curr + ")", n, res);
        }
        if(lp < n) {
            generate(lp + 1, rp, curr+ "(", n, res);
        }
    }
};