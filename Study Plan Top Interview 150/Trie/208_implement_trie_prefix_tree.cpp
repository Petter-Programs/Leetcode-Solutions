struct TrieNode
{
    char current = '-';
    bool real_value = false;
    std::unordered_map<char, TrieNode> connections;
};

class Trie {
private:
    TrieNode first_node;
public:
    Trie() 
    {
        
    }
    
    void insert(string word) 
    {
        TrieNode* current_trie = &first_node;

        for(char c : word)
        {
            current_trie = &current_trie->connections[c];
            current_trie->current = c;
        }

        current_trie->real_value = true;
        
    }
    
    bool search(string word) 
    {
        TrieNode* current_trie = &first_node;

        for(char c : word)
        {
            if(current_trie->connections.find(c) != current_trie->connections.end())
            {
                current_trie = &current_trie->connections[c];
            }
            else
            {
                return false;
            }
        }

        return current_trie->real_value;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* current_trie = &first_node;

        for(char c : prefix)
        {
            if(current_trie->connections.find(c) != current_trie->connections.end())
            {
                current_trie = &current_trie->connections[c];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */