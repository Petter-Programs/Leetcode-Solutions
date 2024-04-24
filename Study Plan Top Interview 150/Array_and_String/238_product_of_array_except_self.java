class Solution {
    public int[] productExceptSelf(int[] nums) {

        int[] answer = new int[nums.length];

        //can work forwards to get
        //1*2*3 --> answer to 4th
        //can work backward to get
        //4*3*2 --> answer to 1st

        //everything else is 
        //first part until own index * second part until own index

        int multiplication = nums[0];
        for(int i = 1; i<nums.length; i++)
        {
            answer[i]=multiplication;
            multiplication*=nums[i];
        }

        multiplication = nums[nums.length-1];
        for(int i = nums.length-2; i>=0; i--)
        {
            if(i>0)
                answer[i]*=multiplication;
            else
                answer[i] = multiplication;
            multiplication*=nums[i];
        }

        return answer;
    }
}