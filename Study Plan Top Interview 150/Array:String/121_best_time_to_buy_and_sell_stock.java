class Solution {
    public int maxProfit(int[] prices) {

    int highestSellAfter[] = new int[prices.length];
    int currentMax = 0;

    for(int i = prices.length-1; i>=0; i--)
    {
        highestSellAfter[i] = currentMax;

        if(prices[i]>currentMax)
            currentMax = prices[i];
    }

    int maxProfitFound = 0;

    for(int i = 0; i<prices.length; i++)
    {
        int potentialProfit = highestSellAfter[i] - prices[i];

        if(potentialProfit>maxProfitFound)
            maxProfitFound = potentialProfit;
    }

    return maxProfitFound;
    }
}