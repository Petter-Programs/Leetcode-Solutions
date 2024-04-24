class Solution {
    public boolean canJump(int[] nums) {

    int maximumReach = 0;

    for(int i = 0; i<nums.length; i++)
    {
        if(i>maximumReach)
            return false;

        int newReach = i+nums[i];

        maximumReach = Math.max(maximumReach, newReach);
    }

    return true;

    }
}