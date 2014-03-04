class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0) return 0;
        int buy = prices[0];
        int maxsofar = 0;
        
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < buy){
                buy = prices[i];
            } else {
                if(prices[i] - buy > maxsofar)
                    maxsofar = prices[i]-buy;
            }
        }
        return maxsofar;
    }
};