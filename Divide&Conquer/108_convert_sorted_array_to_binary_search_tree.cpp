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
    void div_and_conq(TreeNode* parent, vector<int>& nums, int start_idx, int end_idx)
    {

        if(start_idx <= end_idx)
        {
            // std::cout << "div_anc_conq: start_idx is " << start_idx << " and end_idx is " << end_idx << std::endl;
            int mid_point = start_idx + ((end_idx - start_idx) / 2);

            // std::cout << "mid point is " << mid_point << " and therefore it should be excluded" << std::endl;
            int val = nums[mid_point];

            TreeNode *node = new TreeNode();
            node->val = val;

            if(parent->val >= val)
            {
                parent->left = node;
            }

            else
            {
                parent->right = node;
            }

            // std::cout << "divide into.. " << start_idx << "," << mid_point-1 << " and " << mid_point+1 << ", " << end_idx << std::endl;
            div_and_conq(node, nums, start_idx, mid_point-1);
            div_and_conq(node, nums, mid_point+1, end_idx);
        }

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {

        // if i identify the mid-point, then i know i can place
        // all the left half to the left of the tree and same with right half
        // since it is the midpoint, it seems reasonable this would create a balanced tree
        // then can continue the strategy recursively I assume
        TreeNode *parent = new TreeNode();
        div_and_conq(parent, nums, 0, nums.size()-1);
        return parent->left ? parent->left : parent->right;
    }
};