class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        auto alternatives = { 'A', 'C', 'G', 'T' };
        
        std::unordered_set<std::string> already_visited;
        std::queue<std::pair<int, std::string>> candidates;

        candidates.push(std::make_pair(0, startGene));

        while(candidates.size() > 0)
        {
            int moves = candidates.front().first;
            std::string current = candidates.front().second;

            candidates.pop();

            already_visited.emplace(current);

            if(current == endGene)
            {
                return moves;
            }

            for(int i = 0; i<current.length(); ++i)
            {
                for(char alt : alternatives)
                {
                    std::string mutated = current;
                    mutated[i] = alt;

                    auto in_bank = std::find(bank.begin(), bank.end(), mutated);

                    if(in_bank != bank.end() && already_visited.find(mutated) == already_visited.end())
                    {
                        candidates.push(std::make_pair(moves+1, mutated));
                    }
                }
            }
            
        }

        return -1;
        
    }
};