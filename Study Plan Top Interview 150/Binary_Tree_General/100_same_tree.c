/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
 {
     if(p == NULL && q == NULL)
     {
         return true;
     }
 
     // Either, but not both
     if(p == NULL || q == NULL)
     {
         return false;
     }
 
     // Now we know they are not null
     if(p->val != q->val)
     {
         return false;
     }
 
     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
 }