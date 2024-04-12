int maxArea(int* height, int heightSize)
{
    int idx1 = 0;
    int idx2 = heightSize-1;

    int max_area = -1;

    while(idx2>idx1)
    {
        int height_left = height[idx1];
        int height_right = height[idx2];

        int area = min(height_left, height_right) * (idx2-idx1);
        max_area = max(area, max_area);

        if(height_right>height_left)
            idx1++;
        else
            idx2--;

    }

    return max_area;

}

int min(int number_one, int number_two)
{
    if(number_one>=number_two)
        return number_two;
    return number_one;
}

int max(int number_one, int number_two)
{
    if(number_one>=number_two)
        return number_one;
    return number_two;
}