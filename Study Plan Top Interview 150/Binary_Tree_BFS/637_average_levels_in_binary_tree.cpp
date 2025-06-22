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
        std::queue<std::pair<int, TreeNode*>> level_queue;
    public:
        vector<double> averageOfLevels(TreeNode* root) 
        {
            double current_sum = 0.0;
            int current_entries = 0;
            int current_level = 0;
    
            vector<double> solution;
    
            level_queue.push(std::make_pair(0, root));
    
            while(level_queue.size()>0)
            {
                auto top_level = level_queue.front().first;
                auto top_entry = level_queue.front().second;
    
                level_queue.pop();
    
                current_sum+=top_entry->val;
                current_entries++;
    
                if(top_entry->left)
                    level_queue.push(std::make_pair(current_level+1, top_entry->left));
                if(top_entry->right)
                    level_queue.push(std::make_pair(current_level+1, top_entry->right));
    
                if(level_queue.size() == 0 || level_queue.front().first > current_level)
                {
                    double avg = current_sum/current_entries;
                    solution.push_back(avg);
    
                    current_level = level_queue.front().first;
                    current_sum = 0.0;
                    current_entries = 0;
                }
            }
    
            return solution;
        }
    };