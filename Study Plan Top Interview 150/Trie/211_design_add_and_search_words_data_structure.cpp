#define LETTERS_IN_ALPHABET 26
#define WILDCARD '.'

struct TrieNode
{
    bool exists = false;
    std::array<std::unique_ptr<TrieNode>, LETTERS_IN_ALPHABET> connections{};
};

class WordDictionary {
private:
    TrieNode trie_tree;

    bool search_from(TrieNode const * start_node, std::string word)
    {
        TrieNode const * current_node = start_node;

        for(int i = 0; i<word.length(); ++i)
        {
            char c = word[i];
            int idx = c - 'a';

            if(c == WILDCARD)
            {
                std::string word_cpy = word.substr(i);
                
                for(int j = 0; j<current_node->connections.size(); ++j)
                {
                    std::unique_ptr<TrieNode> const& conn = current_node->connections[j];

                    if(conn != nullptr)
                    {
                    
                    word_cpy[0] = 'a' + j;
                    
                    if(search_from(current_node, word_cpy))
                        return true;
                    }
                }

                return false;
            }

            else if(current_node->connections[idx] != nullptr)
            {
                current_node = current_node->connections[idx].get();
            }
            else
            {
                return false;
            }
        }

        return current_node->exists;
    }
public:

    WordDictionary() {
        
    }
    
    void addWord(string word)
    {
        TrieNode* current_node = &trie_tree;

        for(char c : word)
        {
            int idx = c - 'a';

            if(!current_node->connections[idx])
                current_node->connections[idx] = std::make_unique<TrieNode>();

            current_node = current_node->connections[idx].get();
        }

        current_node->exists = true;
    }
    
    bool search(string word) 
    {
        return search_from(&trie_tree, word);   
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */