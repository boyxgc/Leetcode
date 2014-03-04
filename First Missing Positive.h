class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> hash;
        for(int i = 0; i < n; ++i){
            hash.insert(A[i]);
        }
        for(int i = 1; i <= n+1;++i){
            if(hash.find(i) == hash.end()){
                return i;
            }
        }
        return 1;
    }
};