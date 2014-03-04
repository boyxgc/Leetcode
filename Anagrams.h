class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> mmap;
        for(int i = 0; i < strs.size(); ++i){
            string str = strs[i];
            sort(str.begin(), str.end());
            if(mmap.find(str) != mmap.end()){
                (mmap[str]).push_back(strs[i]);
            } else {
                vector<string> tmpv;
                tmpv.push_back(strs[i]);
                mmap[str] = tmpv;
            }
        }
        
        vector<string> ret;
        for(auto it = mmap.begin(); it != mmap.end(); ++it) {
            if(it->second.size() > 1){
                for(int i = 0; i < it->second.size(); ++i)
                    ret.push_back(it->second[i]);
            }
        }
        return ret;
    }
};