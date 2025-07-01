int max(long long a, long long b)
{
    return a >= b ? a : b;
}

int min(long long a, long long b)
{
    return a <= b ? a : b;
}

bool valid_tree(struct TreeNode* root, long long max_value, long long min_value)
{
    if(!root)
    {
        return true;
    }

    long long new_max = min(root->val, max_value);
    long long new_min = max(root->val, min_value);

    if(root->left)
    {
        if(root->left->val >= new_max || root->left->val <= min_value)
        {
            return false;
        }

        bool valid_left = valid_tree(root->left, new_max, min_value);

        if(!valid_left)
        {
            return false;
        }
    }

    if(root->right)
    {
        if(root->right->val <= new_min || root->right->val >= max_value)
        {
            return false;
        }

        return valid_tree(root->right, max_value, new_min);
    }

    return true;

}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) 
{
    long long upper_lim = ((long long)INT_MAX)+1;
    long long lower_lim = ((long long)INT_MIN)-1;

    return valid_tree(root, upper_lim, lower_lim);
}