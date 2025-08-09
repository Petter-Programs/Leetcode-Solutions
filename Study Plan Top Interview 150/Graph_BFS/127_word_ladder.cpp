class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if(std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }

        std::unordered_map<std::string, std::vector<std::string>> mappings;

        for(std::string& word : wordList)
        {
            for(int i = 0; i<word.length(); ++i)
            {
                std::string modified_word = word;
                modified_word[i] = '*';
                mappings[modified_word].push_back(word);
            }
        }

        std::queue<std::pair<int, std::string>> word_queue;
        std::unordered_set<std::string> visited_words;

        word_queue.push(std::make_pair(1, beginWord));

        while(word_queue.size()>0)
        {
            int current_moves = word_queue.front().first;
            std::string current_word = word_queue.front().second;

            word_queue.pop();

            for(int i = 0; i<current_word.length(); ++i)
            {
                std::string current_pattern = current_word;
                current_pattern[i] = '*';

                if(mappings.find(current_pattern) != mappings.end())
                {
                    std::vector<std::string> pattern_words = mappings[current_pattern];

                    for(std::string& word : pattern_words)
                    {
                        if(word == endWord)
                        {
                            return current_moves+1;
                        }

                        if(visited_words.find(word) == visited_words.end())
                        {
                            word_queue.push(std::make_pair(current_moves+1, word));
                            visited_words.emplace(word);
                        }
                    }

                }
            }
        }

        return 0;

        
    }
};