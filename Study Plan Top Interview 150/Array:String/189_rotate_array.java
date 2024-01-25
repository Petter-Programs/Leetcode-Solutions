class Solution {
    public void rotate(int[] nums, int k) {

        int originalNums[] = Arrays.copyOf(nums, nums.length);

        for(int i = 0; i<nums.length; i++)
        {
            int destination = (i+k)%nums.length;
            nums[destination] = originalNums[i];
        }

    }
}