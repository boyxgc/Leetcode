public class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length < 1)
            return 0;
        int buy = prices[0];
        int sell = prices[0];

        int profit = 0;
        for(int i: prices) {
            if(i < sell) {
                profit = profit + sell - buy;
                buy = i;
                sell = i;
            } else {
                sell = i;
            }
        }
        
        profit = profit + sell - buy;
        return profit;
    }
}