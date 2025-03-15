struct ListNode* reverse_segment(struct ListNode* list_before, int length)
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = list_before->next; 

    if(curr == NULL)
    {
        return NULL;
    }

    bool success = true;

    int idx;
    for(idx = 0; idx<length; idx++)
    {
         struct ListNode* next = curr->next;

         if(prev != NULL)
         {
            curr->next = prev;
         }

         prev = curr;
         curr = next;

        if(next == NULL && idx+1<length)
        {
            success = false;
            break;
        }

    }

    // Undo the changes
    if(!success)
    {
        curr = prev;
        prev = NULL;

        for(; idx>=0; idx--)
        {
            struct ListNode* next = curr->next;

            if(prev != NULL)
            {
                curr->next = prev;
            }
            else
            {
                curr->next = NULL;
            }

            prev = curr;
            curr = next;
        }

        return NULL;
    }

    struct ListNode* sublist_end = list_before->next;
    list_before->next = prev;
    sublist_end->next = curr;

    return sublist_end;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    if(k==1 || head == NULL)
    {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    dummy.val = -1;

    struct ListNode* list = &dummy;

    do
    {
        list = reverse_segment(list, k);
    }
    while(list != NULL);

    return dummy.next;
}