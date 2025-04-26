struct SubTree
{
    std::vector<int>::iterator inorder_start_it;
    std::vector<int>::iterator inorder_end_it;
    std::vector<int>::iterator postorder_start_it;
    std::vector<int>::iterator postorder_end_it;
};

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0)
        {
            return nullptr;
        }

        auto root = new TreeNode();
        struct SubTree start_info;
        std::queue<std::pair<struct TreeNode*, struct SubTree>> the_queue;

        root->val = postorder[postorder.size()-1];

        start_info.inorder_start_it = inorder.begin();
        start_info.inorder_end_it = inorder.end();
        start_info.postorder_start_it = postorder.begin();
        start_info.postorder_end_it = postorder.end();

        the_queue.push(std::make_pair(root, start_info));

        while(the_queue.size()>0)
        {
            auto curr = the_queue.front();

            auto subtree = curr.second;

            int subtree_size = std::distance(subtree.inorder_start_it, subtree.inorder_end_it);

            the_queue.pop();

            if(subtree_size > 1)
            {   
                auto root_node = curr.first;
                auto inorder_idx_it = std::find(subtree.inorder_start_it, subtree.inorder_end_it, root_node->val);
                int inorder_idx = std::distance(subtree.inorder_start_it, inorder_idx_it);

                if(inorder_idx > 0)
                {
                    struct SubTree new_subtree;
                    
                    new_subtree.inorder_start_it = subtree.inorder_start_it;
                    new_subtree.inorder_end_it = subtree.inorder_start_it + inorder_idx;
                    new_subtree.postorder_start_it = subtree.postorder_start_it;
                    new_subtree.postorder_end_it = subtree.postorder_start_it + inorder_idx;

                    auto new_node = new TreeNode();

                    new_node->val = *(new_subtree.postorder_end_it-1);
                    root_node->left = new_node;

                    the_queue.push(std::make_pair(new_node, new_subtree));
                }

                if(inorder_idx<subtree_size-1)
                {
                    struct SubTree new_subtree;
                    
                    new_subtree.inorder_start_it = subtree.inorder_start_it + inorder_idx + 1;
                    new_subtree.inorder_end_it = subtree.inorder_end_it;
                    new_subtree.postorder_start_it = subtree.postorder_start_it + inorder_idx;
                    new_subtree.postorder_end_it = subtree.postorder_end_it - 1;

                    auto new_node = new TreeNode();

                    new_node->val = *(new_subtree.postorder_end_it-1);
                    root_node->right = new_node;

                    the_queue.push(std::make_pair(new_node, new_subtree));

                }
            }

        }

        return root;
        
    }
};