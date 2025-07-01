int kth_dfs(struct TreeNode* root, int k, int *k_behind)
{
    if(!root)
    {
        return -1;
    }

    int ans = kth_dfs(root->left, k, k_behind);

    if(ans != -1)
    {
        return ans;
    }

    (*k_behind)++;

    if((*k_behind) == k)
    {
        return root->val;
    }

    ans = kth_dfs(root->right, k, k_behind);

    return ans;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) 
{
    int current_idx = 0;
    return kth_dfs(root, k, &current_idx);
}