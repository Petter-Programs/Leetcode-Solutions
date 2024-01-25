class Solution {
    public int trap(int[] height) {

     int totalWater = 0;

     int heightLeft = 0;
     int heightRight = 0;

     int leftPointer = 0;
     int rightPointer = height.length-1;

     while(leftPointer<=rightPointer)
     {
         boolean samePoint = leftPointer==rightPointer;
         heightLeft = Math.max(heightLeft, height[leftPointer]);
         heightRight = Math.max(heightRight, height[rightPointer]);

         int supportableLevel = Math.min(heightLeft, heightRight);

         int trappedInLeft = supportableLevel-height[leftPointer];

         if(trappedInLeft>=0)
         {
            totalWater+=trappedInLeft;
            leftPointer++;
         }

        if(!samePoint)
        {
            int trappedInRight = supportableLevel-height[rightPointer];
            if(trappedInRight>=0)
            {
                totalWater+=trappedInRight;
                rightPointer--;
            }
        }
     }

     return totalWater;


    }
}