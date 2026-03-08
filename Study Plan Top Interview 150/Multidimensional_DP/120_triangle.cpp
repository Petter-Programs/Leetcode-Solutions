class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
/* 

theoretical solution

min-triangle

       2
    5    6
  11  10  13 
15  11  18  16

minimum of bottom row is 11, so answer is 11

*/

vector<vector<int>> min_triangle;
min_triangle.push_back({triangle[0][0]});

for(int row = 1; row<triangle.size(); ++row)
{
    min_triangle.push_back(std::vector<int>(triangle[row].size()));

    for(int col = 0; col<triangle[row].size(); ++col)
    {
        int straight_above = col < triangle[row-1].size() ? min_triangle[row-1][col] : INT_MAX;
        int above_left = col > 0 ? min_triangle[row-1][col-1] : INT_MAX;

        min_triangle[row][col] = triangle[row][col] + std::min(straight_above, above_left);
    }
}

int min_path = INT_MAX;
for(int col = 0; col<min_triangle[min_triangle.size()-1].size(); ++col)
{
    min_path = std::min(min_path, min_triangle[min_triangle.size()-1][col]);
}

return min_path;

    }
};