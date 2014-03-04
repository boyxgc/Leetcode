class Solution {
public:
    int str2int(string s){
        stringstream ss;
        int res;
        ss << s;
        ss >> res;
        return res;
    }
    
    void restore(string s, int pos, string curr, int sec, vector<string> &res){
        if(pos >= s.size() || sec > 4)
            return;
        for(int i = 1; i <= 3; ++i){
            if(pos + i -1 >= s.size())
                break;
            string tmpstr = s.substr(pos, i);
            if(tmpstr.size() > 1 && tmpstr[0] == '0')
                continue;
            if(str2int(tmpstr) < 256){
                if(pos+i == s.size() && sec == 4) {
                    res.push_back(curr+tmpstr);
                } else {
                    restore(s, pos+i, curr+tmpstr+".", sec+1, res);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res; 
        restore(s, 0, "", 1, res);
        return res;
    }
    
};