class Solution {
    public int hIndex(int[] citations) {

        Arrays.sort(citations);

        int maximum = citations.length;
        int actual = 0;

        for(int i = citations.length-1; i>=0; i--)
        {
            int current = citations[i];
            
            maximum = Math.min(maximum, current);

            if(actual>=maximum)
                break;

            actual++;
        }

        return actual;

    }
}