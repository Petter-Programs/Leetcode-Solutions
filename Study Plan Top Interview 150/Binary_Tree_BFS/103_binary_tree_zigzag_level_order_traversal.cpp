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
 
 class Solution {
    private:
        std::stack<TreeNode*> stack_one;
        std::stack<TreeNode*> stack_two;
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
        {
            vector<vector<int>> solution_vector;
    
            if(!root)
                return solution_vector;
    
            stack_one.push(root);
            solution_vector.push_back(std::vector<int>());
    
            auto stack_to_use = stack_one;
            auto other_stack = stack_two;
    
            bool left_to_right = true;
    
            while(stack_to_use.size() > 0)
            {
                auto curr_entry = stack_to_use.top();
    
                solution_vector.back().push_back(curr_entry->val);
    
                stack_to_use.pop();
    
                if(left_to_right)
                {
                    if(curr_entry->left)
                        other_stack.push(curr_entry->left);
    
                    if(curr_entry->right)
                        other_stack.push(curr_entry->right);
                }
                else
                {
                    if(curr_entry->right)
                        other_stack.push(curr_entry->right);
                    
                    if(curr_entry->left)
                        other_stack.push(curr_entry->left);
                }
    
    
                if(stack_to_use.size() == 0)
                {
                    auto tmp = stack_to_use;
                    stack_to_use = other_stack;
                    other_stack = tmp;
    
                    left_to_right = !left_to_right;
    
                    if(stack_to_use.size()>0)
                        solution_vector.push_back(std::vector<int>());
                }
        
                
            }
    
            return solution_vector;
            
        }
    };