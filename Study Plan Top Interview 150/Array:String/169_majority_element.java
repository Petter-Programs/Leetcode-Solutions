class Solution {
    public int majorityElement(int[] nums) 
    {
        Map<Integer, Integer> pairs = new HashMap<>();

        for(int i = 0; i<nums.length; i++)
        {
            int current = nums[i];
            pairs.compute(current, (k, v) -> (v == null) ? 1 : v + 1);

            if(pairs.get(current) > nums.length/2)
            {
                return current;
            }
        }
    return -1;
    }
}