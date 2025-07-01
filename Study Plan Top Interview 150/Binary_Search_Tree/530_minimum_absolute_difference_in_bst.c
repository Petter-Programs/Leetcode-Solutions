int min(int a, int b)
{
    return a <= b ? a : b;
}

int abs_diff(int a, int b)
{
    return abs(a-b);
}

int dfs_diff(struct TreeNode* root, int *previous_value)
{
    if(!root)
    {
        return INT_MAX;
    }

    int lhs_diff = dfs_diff(root->left, previous_value);

    // Visit
    int diff_prev = abs_diff(root->val, *previous_value); 
    *previous_value = root->val;

    int rhs_diff = dfs_diff(root->right, previous_value);

    int min_sides = min(lhs_diff, rhs_diff);
    return min(diff_prev, min_sides);
}

int getMinimumDifference(struct TreeNode* root) 
{
    int previous_value = INT_MAX;
    return dfs_diff(root, &previous_value);
}