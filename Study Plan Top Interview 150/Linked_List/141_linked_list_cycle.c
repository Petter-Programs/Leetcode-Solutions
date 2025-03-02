/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{

    while(head != NULL)
    {
        if(head->val == INT_MIN)
        {
            return true;
        }
        head->val = INT_MIN;
        head = head->next;
    }

    return false;
    
}