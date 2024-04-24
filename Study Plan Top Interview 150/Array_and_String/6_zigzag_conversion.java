class Solution {
    public String convert(String s, int numRows) {

    String result = "";

    for(int i = 0; i<numRows; i++)
    {
        int currentIndex = i;

        boolean goingUp = i<numRows-1 ? false : true;

        int downDistance = numRows-(i+1) + numRows-1-i;
        int upDistance = 2*i;
        
        while(currentIndex<s.length())
        {
            String character = s.substring(currentIndex, currentIndex+1);
            result+=character;
            
            if(numRows==1)
                currentIndex++;
            else if(!goingUp)
            {
                currentIndex+=downDistance;

                if(i!=0)
                    goingUp = true;
            }
            else
            {
                currentIndex+=upDistance;

                if(i!=numRows-1)
                    goingUp = false;
            }
        }
    }

    return result;

    }
}