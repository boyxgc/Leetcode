class Solution {
public:
    int maxArea(vector<int> &height) {
        /*
        if(height.size() < 2) 
            return 0;
        int maxvol = 0;
        for(int i = 0; i < height.size(); ++i) {
            for(int j = i+1; j < height.size(); ++j) {
                maxvol = max(maxvol, (j-i) * (min(height[i], height[j])));
            }
        }
        return maxvol;
        */
        int i = 0;
        int j = height.size()-1;
        int maxvol = 0;
        while(i < j) {
            maxvol = max(maxvol, (j-i)*min(height[i], height[j]));
            if(height[i] <= height[j]){
                i++;
            }else {
                j--;
            }
        }
        
        return maxvol;
    }
};