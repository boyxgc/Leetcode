class Solution {
public:
    string simplifyPath(string path) {
    	if(path == "")
    		return "";
    
        int size = path.size();
        char * pathch = new char[size+1];
        pathch = strcpy(pathch, path.c_str());
        
        string ret = "";
        if(path[0] == '/'){
            ret = ret+"/";
        }
        
        char * part;
        part = strtok(pathch, "/");
        while(part) {
        	//cout << part << endl;
            if(strcmp(part, "..") == 0) {
                int pos = ret.size()-1;
                if(pos > 0){
                    ret.erase(pos, 1);// erase last '/'
                    pos--;
                }
                while(pos > 0 && ret[pos] != '/'){
                    ret.erase(pos, 1);
                    pos--;
                }
            } else if (strcmp(part, ".") != 0){
                ret = ret + (string)part + "/";
            }
            part = strtok(NULL, "/");
        }
    
        if(ret.size() > 1 && ret[ret.size()-1] == '/'){
        	ret.erase(ret.size()-1, 1);
        }
        return ret;
    }

};