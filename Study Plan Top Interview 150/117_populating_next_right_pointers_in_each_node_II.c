/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

 struct Node* get_rhs_neighbor(struct Node* parent, struct Node* curr)
 {
     if(!parent || !curr)
     {
         return NULL;
     }
 
     if(parent->right && parent->right != curr)
     {
         return parent->right;
     }
     
     // Search for the first non null node
 
     struct Node* uncle = parent->next;
 
     while(uncle != NULL)
     {
         if(uncle->left)
         {
             return uncle->left;
         }
 
         if(uncle->right)
         {
             return uncle->right;
         }
 
         uncle = uncle->next;
     }
 
     return NULL;
 }
 
 struct Node* connect(struct Node* root) 
 {
     struct Node* next_level_start = NULL;
     struct Node* current = root;
 
     while(next_level_start != NULL || current != NULL)
     {
         if(current == NULL)
         {
             if(next_level_start == NULL)
                 break;
 
             current = next_level_start;
             next_level_start = NULL;
         }
 
         if(!next_level_start)
         {
             if(current->left)
             {
                 next_level_start = current->left;
             }
             else if(current->right)
             {
                 next_level_start = current->right;
             }
         }
 
         if(current->left)
             current->left->next = get_rhs_neighbor(current, current->left);
 
         if(current->right)
             current->right->next = get_rhs_neighbor(current, current->right);
 
         current = current->next;
     }
 
     return root;
     
 }