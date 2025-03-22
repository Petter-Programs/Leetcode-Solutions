/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *k_prev = &dummy;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;

    if(head == NULL || k == 0)
    {
        return head;
    }

    int n = 0;
    int list_len = 0;

    while(curr != NULL)
    {
        if(n<k)
        {
            n++;
        }
        else
        {
            k_prev = k_prev->next;
        }

        prev = curr;
        curr = curr->next;
        list_len++;
    }

    if(k == list_len)
    {
        return head;
    }

    if(list_len>k)
    {
        prev->next = dummy.next;
        dummy.next = k_prev->next;
        k_prev->next = NULL;
    }

    else
    {
        int new_k = k % list_len;
        return rotateRight(dummy.next, new_k);
    }

    return dummy.next;
    
}