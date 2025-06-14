/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max(int a, int b)
 {
     if(a>=b)
         return a;
     return b;
 }
 
 int process(struct TreeNode* the_node, int mysum, int *maxsum)
 {
     int sumleft = -INT_MAX;
     int sumright = -INT_MAX;
 
     if(the_node->left)
     {
         sumleft = process(the_node->left, 0, maxsum);
     }
 
     mysum+=the_node->val;
 
     if(sumleft>0)
     {
         mysum+=sumleft;
     }
 
     *maxsum = max(mysum, *maxsum);
 
     if(the_node->right)
     {
         sumright = process(the_node->right, 0, maxsum);
     }
 
     if(sumright>0 && sumright>sumleft)
     {
         mysum = sumright + the_node->val;
     }
 
     *maxsum = max(mysum, *maxsum);
 
     // Consider that we can also connect these two sides.
     // However, if we do this, then we cannot keep connecting up the stack
 
     if(sumleft<0)
     {
         sumleft = 0;
     }
 
     if(sumright<0)
     {
         sumright = 0;
     }
 
     *maxsum = max(sumleft+sumright+the_node->val, *maxsum);
 
     if(mysum<0)
     {
         mysum = 0;
     }
 
     return mysum;
 
 }
 
 // struct TreeNode; int val, struct TreeNode *left, struct TreeNode *right
 int maxPathSum(struct TreeNode* root)
 {
     int max_sum = -INT_MAX;
 
     process(root, 0, &max_sum);
 
     return max_sum;
 }