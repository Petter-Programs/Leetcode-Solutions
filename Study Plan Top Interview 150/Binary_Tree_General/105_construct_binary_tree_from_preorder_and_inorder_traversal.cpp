struct SubtreeInfo
{
    std::vector<int>::iterator preorder_start_it;
    std::vector<int>::iterator preorder_end_it;
    std::vector<int>::iterator inorder_start_it;
    std::vector<int>::iterator inorder_end_it;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }

        std::queue<std::pair<struct TreeNode*, struct SubtreeInfo>> the_queue;

        struct TreeNode* root = new TreeNode();
        root->val = preorder[0];

        struct SubtreeInfo info;
        info.preorder_start_it = preorder.begin();
        info.preorder_end_it = preorder.end();
        info.inorder_start_it = inorder.begin();
        info.inorder_end_it = inorder.end();

        the_queue.push(std::make_pair(root, info));

        while(the_queue.size()>0)
        {
            auto current = the_queue.front();
            auto node = current.first;
            auto info = current.second;
            the_queue.pop();

            auto index_it = std::find(info.inorder_start_it, info.inorder_end_it, node->val);
            int index = std::distance(info.inorder_start_it, index_it);

            int left_side_size = index;
            int right_side_size = std::distance(info.inorder_start_it + index, info.inorder_end_it-1);
            
            if(left_side_size > 0)
            {
                auto left_node_it = info.preorder_start_it+1;

                struct TreeNode* new_node = new TreeNode();
                new_node->val = *left_node_it;
                node->left = new_node;

                struct SubtreeInfo subtree;
                subtree.preorder_start_it = left_node_it;
                subtree.preorder_end_it = subtree.preorder_start_it + index;
                subtree.inorder_start_it = info.inorder_start_it;
                subtree.inorder_end_it = subtree.inorder_start_it + index;

                the_queue.push(std::make_pair(new_node, subtree));
            }

            if(right_side_size > 0)
            {
                auto right_node_it = info.preorder_start_it + index + 1;

                struct TreeNode* new_node = new TreeNode();
                new_node->val = *right_node_it;

                node->right = new_node;

                struct SubtreeInfo subtree;
                subtree.preorder_start_it = right_node_it;
                subtree.preorder_end_it = info.preorder_end_it;
                subtree.inorder_start_it = info.inorder_start_it + index + 1;
                subtree.inorder_end_it = info.inorder_end_it;

                the_queue.push(std::make_pair(new_node, subtree));
            }

        }

        return root;
    }
};