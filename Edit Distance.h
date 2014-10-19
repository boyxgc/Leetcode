class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        
        int I = word1.size();
        int J = word2.size();
        vector<vector<int> > distance(I+1, vector<int>(J+1 , 0));
        
        for(int i = 0; i <= I; ++i) distance[i][0] = i;
        for(int j = 0; j <= J; ++j) distance[0][j] = j;
        
        for(int i = 1; i <= I; ++i) {
            for(int j = 1; j <= J; ++j) {
                distance[i][j] = min(min(distance[i-1][j], distance[i][j-1]) + 1, distance[i-1][j-1] + !(word1[i-1]==word2[j-1]));
                // if(word1[i-1] == word2[j-1]) {
                //     distance[i][j] = distance[i-1][j-1];
                // } else {
                //     distance[i][j] = min(min(distance[i-1][j]/*del*/, distance[i][j-1]/*ins*/), distance[i-1][j-1]/*sub*/) + 1;
                // }
            }
        }
        
        return distance[I][J];
    }
  
};