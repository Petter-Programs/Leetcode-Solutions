/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *return_list = NULL;
    struct ListNode *return_list_head = NULL;
    struct ListNode *inserting_list = NULL;

    int start_list1 = list1 ? list1->val : INT_MAX;
    int start_list2 = list2 ? list2->val : INT_MAX;

    if(start_list1<=start_list2)
    {
        return_list = list1;
        inserting_list = list2;
    }

    // Note that this will also happen if both are NULL
    else
    {
        return_list = list2;
        inserting_list = list1;
    }

    return_list_head = return_list;

    while(inserting_list != NULL)
    {
        struct ListNode *next_to_process = inserting_list->next;

        int val_inserting = inserting_list->val;

        while(return_list->next != NULL && return_list->next->val < val_inserting)
        {
            return_list = return_list->next;
        }

        struct ListNode *next_in_order = return_list->next;

        return_list->next = inserting_list;
        inserting_list->next = next_in_order;

        inserting_list = next_to_process;
    }

    return return_list_head;

}