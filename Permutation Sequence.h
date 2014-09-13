class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n+1, 1);
        string str = "";
        for(int i = 1; i <= n; ++i) {
            factorials[i] = i*factorials[i-1];
            str += to_string(i);
        }
        return findPermutation(str, k-1, factorials);
    }
    
    string findPermutation(string str, int kth, vector<int> &fact) {
        if(kth == 0) {
            return str;
        }
        
        int n = str.size();
        int subtree_size = fact[n-1];
        
        int n_subtree = kth/subtree_size;
        int kth_sub = kth%subtree_size;
        
        char c = str[n_subtree];
        str.erase(str.begin() + n_subtree);
        return c + findPermutation(str, kth_sub, fact);
    }
    
};