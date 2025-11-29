// Heap-based approach

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(k <= nums.size()/2)
        {
            std::priority_queue<int, std::vector<int>, std::less<int>> 
            queue(std::less<int>(), std::move(nums));

            for(int i = 0; i < k - 1; ++i)
            {
                queue.pop();
            }

            return queue.top();
        }
        else
        {
            k = nums.size()-k+1;
            std::priority_queue<int, std::vector<int>, std::greater<int>> 
            queue(std::greater<int>(), std::move(nums));

            for(int i = 0; i < k - 1; ++i)
            {
                queue.pop();
            }

            return queue.top();
        }
    }
};