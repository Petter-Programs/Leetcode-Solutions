/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// hashmap
// number --> pair(Node*, bool visited)

class Solution {
    public:
        Node* cloneGraph(Node* node) 
        {
            if(!node)
            {
                return nullptr;
            }
    
            // Map of unique value + location of copied node
            std::map<int, Node*> node_lookup;
    
            Node* first_cpy = new Node(node->val);
            node_lookup[node->val] = first_cpy;
    
            std::queue<Node*> to_process;
            to_process.push(node);
    
            while(to_process.size() > 0)
            {
                auto curr = to_process.front();
    
                auto neighbors = curr->neighbors;
    
                auto curr_cpy = node_lookup[curr->val];
    
                to_process.pop();
    
                for(auto it = neighbors.begin(); it != neighbors.end(); ++it)
                {
                    auto neighbor_node = *it;
    
                    auto exists_as_copy = node_lookup.find(neighbor_node->val) != node_lookup.end();
    
                    Node *neighbor_cpy;
    
                    if(!exists_as_copy)
                    {
                        neighbor_cpy = new Node(neighbor_node->val);
                        node_lookup[neighbor_node->val] = neighbor_cpy;
                        to_process.push(neighbor_node);
                    }
                    else
                    {
                        neighbor_cpy = node_lookup[neighbor_node->val];
                    }
    
                    curr_cpy->neighbors.push_back(neighbor_cpy);
                }
    
            }
    
            return first_cpy;
    
            
        }
    };