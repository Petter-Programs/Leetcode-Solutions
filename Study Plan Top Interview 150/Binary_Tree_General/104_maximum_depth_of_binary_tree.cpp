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
public:
    int maxDepth(TreeNode* root) 
    {
        std::stack<std::pair<TreeNode*, int>> the_stack;

        int max_depth = 0;

        the_stack.push(std::make_pair(root, 1));

        while(the_stack.size() > 0)
        {
            auto top = the_stack.top();
            auto element = top.first;
            auto depth = top.second;

            the_stack.pop();

            if(element != nullptr)
            {
                max_depth = std::max(max_depth, depth);
                the_stack.push(std::make_pair(element->right, depth+1));
                the_stack.push(std::make_pair(element->left, depth+1));
            }
        }

        return max_depth;

    }
};