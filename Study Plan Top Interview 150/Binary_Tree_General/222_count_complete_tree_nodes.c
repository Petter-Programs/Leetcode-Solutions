int lengthof(struct TreeNode* root)
{
    int len = 0;

    if(!root)
    {
        return len;
    }

    len++;

    while(root->left)
    {
        len++;
        root = root->left;
    }

    return len;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) 
{

    // Important observation:
    // To get the index from lhs of current node when going down the tree;
    // if going left, idx_new = (idx_old * 2) - 1
    // if going right, idx_new = idx_old * 2

    if(!root)
        return 0;

    bool done = false;

    struct TreeNode* curr = root;

    int curr_idx = 1;
    int curr_depth = 1;

    while(!done)
    {
        int length_of_left = lengthof(curr->left);
        int length_of_right = lengthof(curr->right);

        // It follows that length_of_right is also 0
        if(length_of_left == 0)
        {
            done = true;
            break;
        }

        // End must be on left side; go left
        if(length_of_left>length_of_right)
        {
            curr = curr->left;
            curr_idx = curr_idx*2 -1;
        }

        // End must be on right side; go right
        else
        {
            curr = curr->right;
            curr_idx = curr_idx*2;
        }

        curr_depth++;
        
    }


    int nodes_before_last = pow(2, curr_depth-1)-1;

    return nodes_before_last+curr_idx;

}