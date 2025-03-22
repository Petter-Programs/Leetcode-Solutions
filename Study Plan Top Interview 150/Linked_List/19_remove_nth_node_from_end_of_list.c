/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    // strat: always remember the nth node from now

    struct ListNode dummy_node;
    dummy_node.next = head;

    struct ListNode* n_prev = &dummy_node;
    struct ListNode* curr = n_prev->next;

    // according to constraints, this has to be the outcome
    if(curr->next == NULL)
    {
        return NULL;
    }

    int idx = 0;
    while(curr != NULL)
    {
        if(idx<n)
        {
            idx++;
        }

        else if(idx == n)
        {
            n_prev = n_prev->next;
        }

        curr = curr->next;
    }

    struct ListNode* rest_of_list = n_prev->next->next; 

    n_prev->next = rest_of_list;

    return dummy_node.next;
}