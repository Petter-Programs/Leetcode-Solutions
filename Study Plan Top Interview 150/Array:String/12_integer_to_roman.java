class Solution {

    int[] numberList = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    String[] romanList = {"M", "CM", "D", "CD", "C", "XC",
                         "L", "XL", "X", "IX", "V", "IV", "I"};

    public String intToRoman(int num)
    {
        String result = "";

        for(int i = 0; i<numberList.length; i++)
        {
            result+=reduceToRoman(num, numberList[i], romanList[i]);
            num%=numberList[i];
        }

        return result;
    }
    
    String reduceToRoman(int input, int reduceBy, String reduceTo)
    {
        String result = "";
        int instances = input/reduceBy;

        while(instances>0)
        {
            result+=reduceTo;
            instances--;
        }
        return result;
    }
}