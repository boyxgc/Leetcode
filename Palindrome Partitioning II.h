class Solution {
public:
    /*
    bool isPal(string s){
        if(s == "") return true;
        //string s2 = s;
        //reverse(s.begin(), s.end());
        //return s == s2;
        int l = 0; 
        int h = s.size()-1;
        while(l <= h){
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    int minCut(string s) {
        if(s == "") return 0;
        if(isPal(s)) return 0;
        
        int minsofar = INT_MAX;
        for(int i = 1; i < s.size(); ++i){
            string tmpstr = s.substr(0, i);
            if(isPal(tmpstr)){
                int tmp = 1+minCut(s.substr(i));
                minsofar = min(tmp, minsofar);
            }
        }
        return minsofar;
    }*/
    /*
    int minCut(string s){
        if(isPal(s)) return 0;
        
        //mincuts of string [i:j]
        vector<vector<int> >mincut(s.size(), vector<int>(s.size(), 0));
        
        //initialize mincut(i:i)=0, mincut(i,i+1)=!(s[i] == s[i+1])
        for(int i = 0; i < s.size()-1; ++i){
            mincut[i][i] = 0;
            mincut[i+1][i+1] = 0;
            mincut[i][i+1] = !(s[i] == s[i+1]);
        }
        
        //recursion 
        for(int len = 3; len <= s.size(); ++len){
            for(int i = 0; i+len-1 < s.size(); ++i){
                string sub = s.substr(i, len);
                if(isPal(sub)){
                    mincut[i][i+len-1] = 0;
                } else{
                    int tmpmin = mincut[i+1][i+len-1]+1;
                    for(int j = 1; j < len; ++j){
                        //if(isPal(sub.substr(0,j)))
                        //    tmpmin = min(tmpmin, 1+mincut[i+j][i+len-1]);
                        tmpmin = min(tmpmin, mincut[i][i+j-1]+1+mincut[i+j][i+len-1]);
                    }
                    mincut[i][i+len-1] = tmpmin;
                }
            }
        }
        return mincut[0][s.size()-1];
    }*/
    int minCut(string s){
        //if(isPal(s)) return 0;
        if(s.size() < 2) return 0;
        //build a palindrom lookup table
        vector<vector<bool> > isPalindrom(s.size()+1, vector<bool>(s.size()+1, false));
        for(int i = 0; i < s.size(); ++i){
            isPalindrom[i][i] = true;
            isPalindrom[i][i+1] = s[i]==s[i+1];
        }
        for(int len = 3; len <= s.size(); ++len){
            for(int i = 0; i+len-1 < s.size(); ++i){
                if(s[i]==s[i+len-1])
                    isPalindrom[i][i+len-1] = isPalindrom[i+1][i+len-2];
            }
        }
        
        // mincut for s[0:i]
        vector<int> mincut(s.size(), 0);
        
        for(int i = 0; i < s.size(); ++i){
            if(isPalindrom[0][i]){
                mincut[i] = 0;
            } else {
                int tmpmin = INT_MAX;
                for(int j = i; j > 0; --j){
                    if(isPalindrom[j][i])
                        tmpmin = min(tmpmin, 1+mincut[j-1]);
                }
                mincut[i] = tmpmin;
            }
        }
        return mincut[s.size()-1];
    }
};