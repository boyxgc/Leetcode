class Solution {
public:
    string simplifyPath(string path) {
        char *chars = new char[path.size()+1];
        strncpy(chars, path.c_str(), path.size());
        chars[path.size()] = '\0';
        
        string s;
        if(path[0] == '/') {
            s += '/';
        }
        
        char *part = strtok(chars, "/");
        while(part) {
            if(equals(part, "..")) {
                do {
                    if(s.size() == 1) {
                        if(s[0] == '/') {
                            break;
                        } else {
                            s = ".";
                            break;
                        }
                    }
                    s.pop_back();
                }while(s.back() != '/') ;
            } else if(!equals(part, ".")) {
                string str(part);
                s += str + "/";
            }
            
            part = strtok(NULL, "/");
        }
        
        if(s.size() > 1 && s.back() == '/'){
            s.pop_back();
        }
        return s;
    }
    
    bool equals(char *s, const char *t) {
        return strcmp(s, t) == 0;
    }
};