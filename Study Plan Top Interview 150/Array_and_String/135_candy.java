class Solution {
    public int candy(int[] ratings) {
        //5 4 3 2 1
        int[] candyGiven = new int[ratings.length];

        int candyToGive = 1;

        for(int i = 0; i < ratings.length; i++)
        {
            int myRating = ratings[i];
            int previousRating = i > 0 ? ratings[i-1] : ratings[i];

            if(myRating>previousRating)
                candyToGive++;
            else
                candyToGive = 1;

            candyGiven[i] = candyToGive;
        }

        candyToGive = 1;

        for(int i = ratings.length-1; i>=0; i--)
        {
            int myRating = ratings[i];
            int previousRating = i<ratings.length-1 ? ratings[i+1] : ratings[i];

            if(myRating>previousRating)
                candyToGive++;
            else
                candyToGive = 1;

            if(candyToGive>candyGiven[i])
            {
                candyGiven[i] = candyToGive;
            }
        }

        return Arrays.stream(candyGiven).sum();

    }
}