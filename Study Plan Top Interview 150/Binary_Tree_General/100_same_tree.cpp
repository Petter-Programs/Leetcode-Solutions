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
        bool isSameTree(TreeNode* p, TreeNode* q) 
        {
            std::stack<TreeNode*> p_stack;
            std::stack<TreeNode*> q_stack;
    
            p_stack.push(p);
            q_stack.push(q);
    
            while(p_stack.size() > 0 && q_stack.size() > 0)
            {
                auto current_p = p_stack.top();
                auto current_q = q_stack.top();
    
                p_stack.pop();
                q_stack.pop();
    
                if(current_p == nullptr || current_q == nullptr)
                {
                    if(current_p != current_q)
                    {
                        return false;
                    }
    
                    continue;
                }
    
                if(current_p->val != current_q->val)
                {
                    return false;
                }
    
                p_stack.push(current_p->right);
                q_stack.push(current_q->right);
    
                p_stack.push(current_p->left);
                q_stack.push(current_q->left);
            }
    
            if(p_stack.size() != q_stack.size())
            {
                return false;
            }
    
            return true;
    
        }
    };