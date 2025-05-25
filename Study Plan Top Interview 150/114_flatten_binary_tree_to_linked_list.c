// flatten and return last node
struct TreeNode* flatten_subtree(struct TreeNode* root)
{
    if(!root)
    {
        return NULL;
    }

    struct TreeNode* left_side_end = flatten_subtree(root->left);
    struct TreeNode* right_side_end = flatten_subtree(root->right);

    if(root->left)
    {
        left_side_end->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    if(right_side_end)
        return right_side_end;
    
    if(left_side_end)
        return left_side_end;
    
    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) 
{
    flatten_subtree(root);
}


