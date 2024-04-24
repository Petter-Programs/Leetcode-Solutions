class Solution {
    public int removeElement(int[] nums, int val) {

        Queue<Integer> queue = new LinkedList<>();

        int offset = 0;

        for(int i = 0; i<nums.length; i++)
        {
            if(nums[i]==val)
                offset++;

            else
            {
                nums[i-offset] = nums[i];
            }
        }

        return nums.length - offset;

    }
}