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
        TreeNode* invertTree(TreeNode* root) 
        {
            std::queue<TreeNode*> the_queue;
    
            the_queue.push(root);
    
            while(the_queue.size() != 0)
            {
                auto current = the_queue.front();
                the_queue.pop();
    
                if(current != nullptr)
                {
                    the_queue.push(current->right);
                    the_queue.push(current->left);
    
                    auto tmp = current->left;
                    current->left = current->right;
                    current->right = tmp;
                }
            }
    
            return root;
    
        }
    };