class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1=="")
            return word2.size();
        if(word2=="")
            return word1.size();
        
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int> > dist(l1+1, vector<int>(l2+1, l1+l2));
        for(int i = 0; i < l2+1; ++i)
            dist[0][i] = i;
        for(int j = 0; j < l1+1; ++j)
            dist[j][0] = j;
            
        //Ed(i, j) = min{ Ed(i-1, j-1)+!(s[i]==s[j]), Ed(i-1, j)+1, Ed(i, j-1)+1 }
        for(int i = 1; i <= l1; ++i) {
            for(int j = 1; j <= l2; ++j) {
                dist[i][j] = min(min(dist[i-1][j], dist[i][j-1])+1, dist[i-1][j-1] + !(word1[i-1]==word2[j-1]));
            }
        }
        return dist[l1][l2];
    }
};