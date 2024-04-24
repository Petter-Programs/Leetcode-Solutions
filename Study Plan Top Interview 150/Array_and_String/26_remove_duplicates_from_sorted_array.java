class Solution {
    public int removeDuplicates(int[] nums) {

        //constant time contains operation
        Set<Integer> alreadyFound = new HashSet<>();

        int offset = 0;

        for(int i = 0; i<nums.length; i++)
        {

            int current = nums[i];
            boolean unique = alreadyFound.add(current);

            if(!unique)
            {
                offset++;
            }
            else
            {
                nums[i-offset] = current;
            }

        }

        return nums.length-offset;

    }
}