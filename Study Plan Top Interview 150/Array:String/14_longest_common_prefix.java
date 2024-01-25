class Solution {
    public String longestCommonPrefix(String[] strs)
    {
        String subString = strs[0];
        for(int i = 1; i<strs.length; i++)
        {
            subString = returnPrefix(subString, strs[i]);
            if(subString.equals(""))
                return subString;
        }

        return subString;
    }

    public String returnPrefix(String stringOne, String stringTwo)
    {
        String output = "";
        int stringOneIndex = 0;
        int stringTwoIndex = 0;
        
        while(stringOne.length()>stringOneIndex 
             && stringTwo.length()>stringTwoIndex
             && stringOne.charAt(stringOneIndex)
             == stringTwo.charAt(stringTwoIndex))
        {
            output+=stringOne.charAt(stringOneIndex);
            stringOneIndex++;
            stringTwoIndex++;
        }

        return output;
    }
}