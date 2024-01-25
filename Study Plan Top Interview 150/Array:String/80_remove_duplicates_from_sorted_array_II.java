class Solution {
    public int removeDuplicates(int[] nums) {

        int lastSeen = nums[0];
        int lastSeenCount = 1;
        int offset = 0;
        for(int i = 1; i<nums.length; i++)
        {
            if(lastSeen==nums[i])
            {
                lastSeenCount++;
            }
            else
            {
                lastSeenCount = 1;
            }

            if(lastSeenCount > 2)
            {
                offset++;
            }

            lastSeen = nums[i];
            nums[i-offset] = lastSeen;
        }

        return nums.length-offset;

    }
}