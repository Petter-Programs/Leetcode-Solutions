class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) 
    {
        Queue<Integer> queue = new LinkedList<>();

        int nums1Index = 0;
        int nums2Index = 0;

        for(int i = 0; i<m+n; i++)
        {
            int val1 = nums1Index>=m ? Integer.MAX_VALUE : nums1[nums1Index];
            int val2 = nums2Index>=n ? Integer.MAX_VALUE : nums2[nums2Index];
            int val3 = queue.isEmpty() ? Integer.MAX_VALUE : queue.peek();

            //val1 is not lowest, we need to replace it
            if(val1>val2 || val1>val3)
            {
                queue.offer(val1);

                if(val2<=val3)
                {
                    nums1[i] = val2;
                    nums2Index++;
                }
                //take from the queue
                else
                {
                    nums1[i] = val3;
                    queue.poll();
                }
            }
                        
            nums1Index++;
        }
    }
}