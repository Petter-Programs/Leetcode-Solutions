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
        std::queue<std::pair<int, TreeNode*>> process_queue;
    public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            vector<vector<int>> solution_vector;
    
            if(!root)
            {
                return solution_vector;
            }
    
            process_queue.push(std::make_pair(0, root));
    
            solution_vector.push_back(std::vector<int>());
    
            while(process_queue.size()>0)
            {
                auto current_lvl = process_queue.front().first;
                auto current_elem = process_queue.front().second;
    
                solution_vector.back().push_back(current_elem->val);
    
                process_queue.pop();
    
                if(current_elem->left)
                {
                    process_queue.push(std::make_pair(current_lvl+1, current_elem->left));
                }
    
                if(current_elem->right)
                {
                    process_queue.push(std::make_pair(current_lvl+1, current_elem->right));
                }
    
                if(process_queue.size()>0 && process_queue.front().first > current_lvl)
                {
                    solution_vector.push_back(std::vector<int>());
                }
    
            }
    
            return solution_vector;
        }
    };