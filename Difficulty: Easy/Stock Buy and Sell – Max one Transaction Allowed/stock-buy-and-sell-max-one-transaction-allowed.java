class Solution {
    public int maxProfit(int[] prices) {
        // Code here
        int n = prices.length;
        int maxprofit = 0;
        int minprice = prices[0];
        for(int i = 0; i<n; i++){
            minprice = Math.min(prices[i],minprice);
            int currprofit = prices[i]- minprice;
            maxprofit = Math.max(maxprofit,currprofit);
        }
        return maxprofit;
    }       
}   