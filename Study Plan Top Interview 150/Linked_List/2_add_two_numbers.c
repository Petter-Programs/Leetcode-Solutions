/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;

    struct ListNode* l1_bup = l1;
    struct ListNode* l2_bup = l2;

    int l1_depth = 0;
    int l2_depth = 0;

    struct ListNode* return_list_end;

    while(l1 != NULL || l2 != NULL)
    {
        int digit_one = l1 ? l1->val : 0;
        int digit_two = l2 ? l2->val : 0;

        int sum = carry + digit_one + digit_two;

        carry = 0;

        if(sum>=10)
        {
            sum-=10;
            carry=1;
        }

        if(l1 != NULL)
        {
            l1->val = sum;

            if(l1->next == NULL)
            {
                return_list_end = l1;
            }

            l1_depth++;
            l1 = l1->next;
            
        }

        if(l2 != NULL)
        {
            l2->val = sum;

            if(l2->next == NULL)
            {
                return_list_end = l2;
            }

            l2 = l2->next;
            l2_depth++;
        }
    }

    struct ListNode* return_list_start;

    if(l1_depth > l2_depth)
    {
        return_list_start = l1_bup;
    }
    else
    {
        // since we check l2->next == NULL after,
        // it will have the return_list_end if the depths are equal
        return_list_start = l2_bup;
    }

    if(carry == 1)
    {
        struct ListNode *extra = malloc(sizeof(struct ListNode));
        extra->val = 1;
        extra->next = NULL;
        return_list_end->next = extra;
    }

    return return_list_start;
    
}