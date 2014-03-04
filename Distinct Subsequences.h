/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
class Solution {
public:
/*
    void dfs(string S, int pos1, string T, int pos2, int &ret){
        if(pos1 >= S.size() || pos2 >= T.size())
            return;
        if(S.size()-pos1 < T.size()-pos2)
            return;
        for(int i = pos1; i < S.size(); ++i){
            if(S[i] == T[pos2]){
                if(pos2 == T.size()-1){
                    ret++;
                } else{
                    dfs(S, i+1, T, pos2+1, ret);
                }
            }
        }
    }
    int numDistinct(string S, string T) {
        int ret = 0;
        dfs(S, 0, T, 0, ret);
        return ret;
    }*/
    /*
    int numDistinct(string S, string T) {
        int rows = T.size();
        //create table
        vector<vector<int> > table(rows);
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < S.size(); ++j){
                if(S[j] == T[i]) {
                    table[i].push_back(j);
                }
            }
        }
        // res[i][j] = sum(res[i-1][k]), where table[i-1][k] < table[i][j]
        vector<vector<int> > res(rows);
        for(int i = 0; i < table[0].size(); ++i) {
            res[0].push_back(1);
        }
        for(int i = 1; i < rows; ++i) {
            for(int j = 0; j < table[i].size(); ++j) {
                int tmpsum = 0;
                for(int k = 0; k < table[i-1].size(); ++k){
                    if(table[i-1][k] < table[i][j])
                        tmpsum += res[i-1][k];
                }
                res[i].push_back(tmpsum);
            }
        }
        int ret = 0;
        for(int i = 0; i < res[rows-1].size(); ++i){
            ret += res[rows-1][i];
        }
        
        return ret;
    }*/
    int numDistinct(string S, string T) {
        vector<vector<int> > table(S.size()+1, vector<int>(T.size()+1, 0));
        for(int i = 0; i <= S.size(); ++i)
            table[i][0] = 1;
        for(int i = 1; i <= S.size(); ++i){
            for(int j = 1; j <= T.size(); ++j){
                if(S[i-1] == T[j-1]){
                    table[i][j] = table[i-1][j-1] + table[i-1][j];
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[S.size()][T.size()];
    }
};