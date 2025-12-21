class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        // Stores slopes as (dx, dy) instead of double-precision representation,
        // to avoid rounding errors
        
        auto pair_hash = [](const std::pair<int, int>& p) 
        {
            return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
        };

        int max_found = 1;

        for(int i = 0; i<points.size(); ++i)
        {
            std::vector<int> const& point1 = points[i];

            std::unordered_map<std::pair<int, int>, int, decltype(pair_hash)> gradients(0, pair_hash);

            for(int j = i+1; j<points.size(); ++j)
            {
                std::vector<int> const& point2 = points[j];

                int dx = point2[0]-point1[0];
                int dy = point2[1]-point1[1];

                int div = std::gcd(dx, dy);
                
                // div will never be 0 because input does not contain duplicates
                // and we are avoiding creating comparisons for own point
                dx /= div;
                dy /= div;

                // After dividing by gcd, each slope has exactly two equivalent
                // representations: (dx, dy) and (-dx, -dy).
                // We must map both to the same hash key.
                // We arbitrarily enforce a direction:
                //   - dx must be positive
                //   - if dx == 0 (vertical line), dy must be positive
                // If the vector does not follow this rule, flip its sign.
                if(dx < 0 || (dx == 0 && dy < 0))
                {
                    dx = -dx;
                    dy = -dy;
                }

                auto& grad = ++gradients[std::make_pair(dx, dy)];

                // We want the count to start at 2 because always involves 2 points
                if(grad==1)
                {
                    ++grad;
                }

                max_found = std::max(max_found, grad);
            }
        }

        return max_found;
    }
};