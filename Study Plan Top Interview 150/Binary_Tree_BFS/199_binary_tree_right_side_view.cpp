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
    std::queue<std::pair<int, TreeNode*>> level_queue;
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> sol_vector;

        int current_level = 0;
        bool level_printed = false;

        level_queue.push(std::make_pair(current_level, root));

        while(level_queue.size() > 0)
        {
            auto top = level_queue.front();

            if(top.second == nullptr)
                break;
            
            current_level = top.first;

            level_queue.pop();

            if(level_queue.size()==0 || level_queue.front().first > current_level)
            {
                sol_vector.push_back(top.second->val);
            }

            if(top.second->left)
                level_queue.push(std::make_pair(current_level+1, top.second->left));

            if(top.second->right)
                level_queue.push(std::make_pair(current_level+1, top.second->right));
            

        }

        return sol_vector;

    }
};