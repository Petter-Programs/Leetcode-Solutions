/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class BSTIterator {
    private:
        std::stack<TreeNode*> nodes_above;
        TreeNode* current_node;
        
        TreeNode* to_bottom(TreeNode* start)
        {
            while(start->left)
            {
                nodes_above.push(start);
                start = start->left;
            }
    
            return start;
        }
    public:
        BSTIterator(TreeNode* root) 
        {
            auto bottom = to_bottom(root);
            nodes_above.push(bottom);
            current_node = new TreeNode(bottom->val-1);
        }
        
        int next() 
        {
            if(current_node->right)
            {
                TreeNode *bottom = to_bottom(current_node->right);
                current_node = bottom;
            }
            else
            {
                current_node = nodes_above.top();
                nodes_above.pop();
            }
    
            return current_node->val;
        }
        
        bool hasNext() 
        {
            return current_node->right != nullptr || nodes_above.size()>0;   
        }
    };
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */