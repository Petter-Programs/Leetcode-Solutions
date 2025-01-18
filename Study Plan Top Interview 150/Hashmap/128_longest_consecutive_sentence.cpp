class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
       std::unordered_map<int, std::pair<int, int>> connections;

       for(auto it = nums.begin(); it != nums.end(); ++it) // O(n)
       {
        int prev_number = *it-1;
        int next_number = *it+1;

        if(connections.find(prev_number) != connections.end()) // O(1)
        {
            connections[prev_number].second = *it;
        }
        else
        {
            prev_number = INT_MIN;
        }

        if(connections.find(next_number) != connections.end())
        {
            connections[next_number].first = *it;
        }
        else
        {
            next_number = INT_MAX;
        }
        
        connections[*it] = std::make_pair(prev_number, next_number);

       }

       int longest_found = 0;

       for(auto it = connections.begin(); it!=connections.end(); ++it)
       {
        auto connection = it->second;

        // We're only ever checking the ends of unique chains within the array,
        // so will not move past O(n) complexity
        if(connection.second == INT_MAX)
        {
            int num_curr = it->first;
            int curr_chain_len = 0;

            while(num_curr != INT_MIN)
            {
                num_curr = connections[num_curr].first;
                curr_chain_len++;
            }

            if(curr_chain_len > longest_found)
                longest_found = curr_chain_len;

        }
        

       }
    
       return longest_found;
        
    }
};