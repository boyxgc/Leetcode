class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool> > match(s1.size()+1, vector<bool>(s2.size()+1, false));
        
        match[0][0] = true;
        for(int i = 1; i <= s1.size(); ++i) {
           if(s1[i-1] == s3[i-1])
                match[i][0] = true;
            else
                break;
        }
        for(int i = 1; i <= s2.size(); ++i) {
           if(s2[i-1] == s3[i-1])
                match[0][i] = true;
            else
                break;
        }
        
        for(int i = 1; i <= s1.size(); ++i) {
            for(int j = 1; j <= s2.size(); ++j) {
                char c1 = s1[i-1];
                char c2 = s2[j-1];
                char c3 = s3[i+j-1];
                
                match[i][j] = match[i-1][j]&&(c1==c3) || match[i][j-1]&&(c2==c3);
                /*if(c1 == c3){
                    match[i][j] = match[i-1][j] || match[i][j];
                }
                if(c2 == c3) {
                    match[i][j] = match[i][j-1] || match[i][j];
                }*/
            }
        }
        return match[s1.size()][s2.size()];
    }
    /*
    bool isI(string s1, string s2, string s3, int i, int j, int k) {
        if (i < 0 && j < 0 && k < 0)
            return true;
        if(k < 0)
            return false;
        bool flag = false;
        if(i >= 0 && s1[i] == s3[k]){
            flag = isI(s1, s2, s3, i-1, j, k-1);
        }
        if(j >= 0 && s2[j] == s3[k]) {
            flag = flag || isI(s1, s2, s3, i, j-1, k-1);
        }
        return flag;
    }*/
};