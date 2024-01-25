class Solution {
    public String reverseWords(String s) 
    {
        String answer = "";
        String[] solution = s.split("\\s+");
        for(int i = solution.length-1; i>=0; i--)
        {
            answer+=solution[i];
            answer+=" ";
        }
        return answer.trim();
    }
}