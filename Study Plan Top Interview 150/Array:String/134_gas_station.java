class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

      //whenever you land on this, regardless of what you have
      //in the bank, you lose/gain this much
      int[] diffs = new int[gas.length];

      int totalCost = 0;
      int totalGas = 0;

      for(int i = 0; i<gas.length; i++)
      {
          diffs[i] = gas[i]-cost[i];

          totalCost+=cost[i];
          totalGas+=gas[i];
      }

      if(totalGas<totalCost)
        return -1;

      //At this point, we know there is a solution
      //The only question is where (we also know solution is unique)

      int currentIndex = 0;
      int currentGas = 0;

      for(int i = 0; i<gas.length; i++)
      {
          currentGas+=diffs[i];
          if(currentGas<0)
          {
              currentGas = 0;
              currentIndex = i+1;
          }
      }

      return currentIndex;

    }
}