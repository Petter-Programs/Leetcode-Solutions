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
        bool isSymmetric(TreeNode* root) 
        {
            if(root == nullptr)
            {
                return true;
            }
    
            std::queue<TreeNode*> queue;
    
            queue.push(root->left);
            queue.push(root->right);
    
            while(queue.size()>0)
            {
                auto first = queue.front();
                queue.pop();
                auto second = queue.front();
                queue.pop();
    
                if(first != nullptr && second != nullptr)
                {
                    if(first->val != second->val)
                        return false;
    
                    queue.push(first->left);
                    queue.push(second->right);
    
                    queue.push(first->right);
                    queue.push(second->left);
                }
    
                else if(!(first == nullptr && second == nullptr))
                {
                    return false;
                }
            }
    
            return true;
            
        }
    };