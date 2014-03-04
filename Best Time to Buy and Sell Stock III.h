class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //go from left to right, calculate out maxprofit from 0 to i for each i
        //go from right to left, calculate out maxprofit from i to end for each i
        if(prices.size() == 0) return 0;
        
        int ret = 0;
        vector<int> maxProfit(prices.size(), 0);
        
        //left to right
        int buy = prices[0];
        int maxsofar = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < buy){
                buy = prices[i];
            }
            if(prices[i]- buy > maxsofar){
                maxsofar = prices[i] - buy;
            }
            maxProfit[i] = maxsofar;
        }
        
        //right to left
        int sell = prices.back();
        maxsofar = 0;
        for(int i = prices.size()-1; i >= 0; --i){
            if(maxProfit[i] + maxsofar > ret)
                ret = maxProfit[i] + maxsofar;
            if(prices[i] > sell)
                sell = prices[i];
            if(sell - prices[i] > maxsofar)
                maxsofar = sell-prices[i];
        }
        
        return ret;
    }
};