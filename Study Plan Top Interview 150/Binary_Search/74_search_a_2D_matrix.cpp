class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int start_row = 0;
        int end_row = matrix.size()-1;

        while(start_row <= end_row)
        {
            int mid_row = (start_row+end_row)/2;
            int curr = matrix[mid_row][0];

            if(curr == target)
                return true;

            if(curr < target)
                start_row = mid_row+1;
            
            else
                end_row = mid_row-1;
        }

        if(end_row < 0)
            return false; 

        int start_col = 0;
        int end_col = matrix[0].size()-1;

        while(start_col <= end_col)
        {
            int mid_col = (start_col + end_col)/2;

            if(matrix[end_row][mid_col] == target)
                return true;

            if(matrix[end_row][mid_col] < target)
                start_col = mid_col+1;

            else
                end_col = mid_col-1;
        }

        return false;
    }
};