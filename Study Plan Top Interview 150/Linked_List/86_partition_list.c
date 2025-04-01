/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* partition(struct ListNode* head, int x)
 {  
    if(head == NULL)
    {
        return head;
    }

    struct ListNode dummy_a;
    struct ListNode dummy_b;
    
    dummy_a.next = NULL;
    dummy_b.next = NULL;

    struct ListNode* a_list = &dummy_a;
    struct ListNode* b_list = &dummy_b;

    struct ListNode* current = head;

    while(head != NULL)
    {
        struct ListNode *head_next = head->next;

        if(head->val < x)
        {
            a_list->next = head;
            a_list = a_list->next;   
            a_list->next = NULL;
        }
        else
        {
            b_list->next = head;
            b_list = b_list->next;
            b_list->next = NULL;
        }

        head = head_next;
    }

    if(dummy_a.next == NULL)
    {
        return dummy_b.next;
    }

    if(dummy_b.next == NULL)
    {
        return dummy_a.next;
    }

    a_list->next = dummy_b.next;
    return dummy_a.next;
 }