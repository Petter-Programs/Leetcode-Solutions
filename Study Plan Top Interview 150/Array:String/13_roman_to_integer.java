class Solution {
    public int romanToInt(String s)
    {
        int value = 0;

        String prev = ".";

        String EXCEPTION_PREV = "IXC";
        String EXCEPTION_FOLL = "VXLCDM";

        for(int i = s.length()-1; i>=0; i--)
        {
            String c = s.substring(i,i+1);

            int worth = value(c);

            if(EXCEPTION_PREV.contains(c) && EXCEPTION_FOLL.contains(prev)
            && value(c)<value(prev))
            {
                value-=worth;
            }
            else
            {
                value+=worth;
            }

            prev = c;

        }
        return value;
    }

    public int value(String c)
    {
        switch(c)
        {
            case "I":
                return 1;
            case "V":
                return 5;
            case "X":
                return 10;
            case "L":
                return 50;
            case "C":
                return 100;
            case "D":
                return 500;
            case "M":
                return 1000;
            default:
                return -9000;
        }
    }
}