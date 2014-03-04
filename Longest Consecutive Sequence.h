class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash;
        for(int i = 0; i < num.size(); ++i){
            hash.insert(num[i]);
        }
        
        int maxlen = 1;
        for(int i = 0; i < num.size(); ++i){
            int tmplen = 1;
            int tmpnum = num[i]+1;
            while(hash.find(tmpnum) != hash.end()){
                hash.erase(tmpnum);
                tmpnum++;
                tmplen++;
            }
            tmpnum = num[i]-1;
            while(hash.find(tmpnum) != hash.end()){
                hash.erase(tmpnum);
                tmpnum--;
                tmplen++;
            }
            maxlen = max(maxlen, tmplen);
        }
        return maxlen;
    }
};