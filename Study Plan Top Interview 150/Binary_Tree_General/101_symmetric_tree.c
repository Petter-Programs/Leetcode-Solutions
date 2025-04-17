bool symmetric_sides(struct TreeNode* node1, struct TreeNode* node2)
{
    if(node1 == NULL && node2 == NULL)
    {
        return true;
    }

    if(node1 == NULL || node2 == NULL)
    {
        return false;
    }

    if(node1->val != node2->val)
    {
        return false;
    }

    return symmetric_sides(node1->left, node2->right) && symmetric_sides(node2->left, node1->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) 
{
    if(root == NULL)
    {
        return true;
    }

    return symmetric_sides(root->left, root->right);
}