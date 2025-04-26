/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) 
        {
            if(root == NULL)
                return root;
                
            // first instinct: breath first search so queue
            // if queue has next and level is equal, set next of current node to queue's next
    
            std::queue<std::pair<Node*, int>> the_queue;
    
            the_queue.push(std::make_pair(root, 0));
    
            while(the_queue.size() > 0)
            {
                auto curr = the_queue.front();
                auto curr_node = curr.first;
                auto curr_level = curr.second;
    
                the_queue.pop();
            
                curr_node->next = NULL;
    
                if(the_queue.size()>0 && curr_level == the_queue.front().second)
                {
                    curr_node->next = the_queue.front().first;
                }
    
                if(curr_node->left != NULL)
                    the_queue.push(std::make_pair(curr_node->left, curr_level+1));
    
                if(curr_node->right != NULL)
                    the_queue.push(std::make_pair(curr_node->right, curr_level+1));
    
            } 
    
    
            return root;
    
        }
    };