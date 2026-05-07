class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int minIdx = 0;
        int maxIdx = prices.length - 1;
        int profit = 0;

        for (int i = 0; i < prices.length; ++i)
        {
            if (prices[i] <= min)
            {
                min = prices[i];
                minIdx = i;
            }
            if (prices[i] >= max)
            {
                max = prices[i];
                maxIdx = i;
            }
            if (maxIdx > minIdx && max - min > profit) profit = max - min;
            if (maxIdx < minIdx) max = Integer.MIN_VALUE;
        }

        return profit;
    }
}