class Solution {
    public int jump(int[] nums) {

    int currentReach = 0;
    int jumps = 0;
    int bestReach = 0;

    for(int i = 0; i < nums.length; i++)
    {
        bestReach = Math.max(bestReach, nums[i]+i);

        if(currentReach>=nums.length-1)
            break;
        
        if(i>=currentReach)
        {
            currentReach = bestReach;
            jumps++;
        }
        
    }

    return jumps;

    }
}