int find_idx(int *inorder, int target)
{
    int idx = 0;
    while(*inorder != target)
    {
        inorder++;
        idx++;
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
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
{
    if(!inorder || inorderSize<=0)
    {
        return NULL;
    }

    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    int current_val = postorder[postorderSize-1];

    node->val = current_val;

    int idx = find_idx(inorder, current_val);

    node->left = buildTree(inorder, idx, postorder, idx);
    node->right = buildTree(inorder+idx+1, inorderSize-idx-1, postorder+idx, postorderSize-idx-1);

    return node;

    // theoretical approach
    // root node has to be right most element of postorder
    // we can then use inorder to find leftside subset and rightside subset
    // and we can continue recursively

}