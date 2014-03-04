class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,"",res);
        
        return res;
    }
    void generate(int n, int sum, string str, vector<string> &res){
        //let '(' be 1, and ')' be -1, anytime, the sum should be >= 0
        if(n == 0 && sum == 0) {
            res.push_back(str);
            return;
        }
        
        if(n > 0){
            generate(n-1, sum+1, str+"(", res);
        }
        if(sum > 0){
            generate(n, sum-1, str+")", res);
        }
    }
};