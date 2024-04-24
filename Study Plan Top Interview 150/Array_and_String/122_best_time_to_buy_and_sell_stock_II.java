class Solution {
    public int maxProfit(int[] prices) 
    {
        int currentTotalProfit = 0;
        int currentMaxSell = prices[1%prices.length];

        int leftPointer = 0;
        int rightPointer = 1;

        while(rightPointer < prices.length)
        { 
            int buyPrice = prices[leftPointer];
            int sellPrice = prices[rightPointer];

            if(sellPrice<buyPrice)
            {
                if(currentMaxSell>buyPrice)
                    currentTotalProfit+=(currentMaxSell-buyPrice);
                
                leftPointer = rightPointer;
                currentMaxSell = sellPrice;
            }
            else
            {
                if(sellPrice<currentMaxSell)
                {
                    currentTotalProfit+=(currentMaxSell-buyPrice);
                    leftPointer = rightPointer-1;
                    rightPointer = leftPointer;
                }
                else
                {
                    currentMaxSell = sellPrice;
                }
            }

            rightPointer++;
            
            if(rightPointer == prices.length && currentMaxSell>buyPrice)
            {
                currentTotalProfit+=(currentMaxSell-buyPrice);
            }
        }
    
    return currentTotalProfit;

    }
}