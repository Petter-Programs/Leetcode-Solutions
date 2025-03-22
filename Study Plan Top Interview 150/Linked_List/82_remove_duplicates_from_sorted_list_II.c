/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode dummy_node;
    dummy_node.next = head;

    struct ListNode *current = head;
    struct ListNode *last_unique = &dummy_node;
    
    while(current != NULL)
    {
        int curr_val = current->val;

        if(current->next == NULL || current->next->val != curr_val)
        {
            last_unique->next = current;
            last_unique = current;
        }
        else
        {
            while(current->next != NULL && current->next->val == curr_val)
            {
                current = current->next;
            }

            if(current->next == NULL)
            {
                last_unique->next = NULL;
            }
        }

        current = current->next;
    }

    return dummy_node.next;
    
}