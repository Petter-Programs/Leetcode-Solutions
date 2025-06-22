/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
 {
     // Base case: not found in this area of the tree
     if(!root)
     {
         return NULL;
     }
 
     // Base case: this node is a match.
     // If this is the root of the whole tree, there is no other option, so this is fine
     // No need to explore the remaining left or right subtrees as this match marks a lower limit of common ancestry
     if(root == p || root == q)
     {
         return root;
     }
 
     struct TreeNode* left_find = lowestCommonAncestor(root->left, p, q);
     struct TreeNode* right_find = lowestCommonAncestor(root->right, p, q);
 
     // This must be the point of their last common ancestor
     if(left_find && right_find)
     {
         return root;
     }
 
     // Must be on the side of the tree where we found first instance of p/q
     return left_find ? left_find : right_find;
 }