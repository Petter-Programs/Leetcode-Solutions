int find_idx(int *array, int val)
{
    int idx = 0;

    while(*array != val)
    {
        idx++;
        array++;
    }

    return idx;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
    if(!inorder || !preorder)
        return NULL;
        
    if(preorderSize<=0)
    {
        return NULL;
    }

    struct TreeNode *new_node = malloc(sizeof(struct TreeNode));

    new_node->val = preorder[0];

    int mid = find_idx(inorder, new_node->val);

    new_node->left = buildTree(preorder+1, mid, inorder, mid);
    new_node->right = buildTree(preorder+mid+1, preorderSize-mid-1, inorder+mid+1, inorderSize-mid-1);

    return new_node;
}