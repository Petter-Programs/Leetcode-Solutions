/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 #define MAX_NUMBER_STRING 11

 int process_node(struct TreeNode* node, char *current_number, int curr_depth)
 {
     int sum = 0;
 
     current_number[curr_depth] = node->val + '0';
     current_number[curr_depth+1] = '\0';
 
     if(node->left != NULL)
     {
         sum += process_node(node->left, current_number, curr_depth+1);
     }
 
     if(node->right != NULL)
     {
         sum += process_node(node->right, current_number, curr_depth+1);
     }
 
     if(!node->left && !node->right)
     {
         sum += atoi(current_number);
         current_number[curr_depth] = '\0';
     }
 
     return sum;
 }
 
 int sumNumbers(struct TreeNode* root) 
 {
     char number_string[MAX_NUMBER_STRING];
     return process_node(root, number_string, 0);
 }