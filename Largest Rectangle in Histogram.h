class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        //assume each bar as the lowest one in a rectangle
        //find the consecutive left bound and right bouds 
        //within which each bar is no lower than that bar
        int size = height.size();
        if(size == 0) return 0;
        int maxsofar = 0;
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        
        for(int i = 0; i < height.size(); ++i){
            int tmp = i;
            while(tmp-1 >= 0 && height[tmp-1] >= height[i]){
                tmp = left[tmp-1];
            }
            left[i] = tmp;
        }
        for(int i = height.size()-1; i >= 0; --i){
            int tmp = i;
            while(tmp+1 < height.size() && height[tmp+1] >= height[i]){
                tmp = right[tmp+1];
            }
            right[i] = tmp;
            maxsofar = max(maxsofar, (right[i]-left[i]+1)*height[i]);
        }
        
        return maxsofar;
    }
};