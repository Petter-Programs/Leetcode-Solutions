bool pathsum_dfs(struct TreeNode* current, int currentSum, int targetSum)
{
    if(!current)
    {
        return false;
    }

    int new_sum = current->val + currentSum;

    if(!current->left && !current->right)
    {
        return new_sum == targetSum;
    }

    return pathsum_dfs(current->left, new_sum, targetSum)
    || pathsum_dfs(current->right, new_sum, targetSum);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) 
{
    if(!root)
        return false;

    return pathsum_dfs(root, 0, targetSum);
}