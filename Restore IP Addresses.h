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

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        return restore(s, 4);
    }
    
    vector<string> restore(string s, int parts) {
        vector<string> res;
        if(s.size() > 3*parts || s.size() < parts) return res;

        if(parts == 1) {
            int i = atoi((char *)s.c_str());
            if(i < 256 && !(s.size()>1 && s[0] == '0')) {
                res.push_back(s);
            }
            return res;
        }
        
        if(s[0] == '0') {
            vector<string> v = restore(s.substr(1), parts-1);
            for(int j = 0; j < v.size(); ++j) {
                res.push_back("0."+v[j]);
            }
            return res;
        }
        
        for(int i = 1; i < 4 && i <= s.size(); ++i) {
            string str = s.substr(0, i);
            int num = atoi((char *)str.c_str());
            if(num < 256) {
                vector<string> v = restore(s.substr(i), parts-1);
                for(int j = 0; j < v.size(); ++j) {
                    res.push_back(str+"."+v[j]);
                }
            }
        }
        return res;
    }
};