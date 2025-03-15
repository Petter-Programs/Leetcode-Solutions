/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    if(left==right)
        return head;

    struct ListNode dummy_node;
    dummy_node.next = head;

    struct ListNode *current_node = head;
    struct ListNode *last_node = &dummy_node;

    struct ListNode *before_left;
    struct ListNode *after_right;

    struct ListNode *original_left;

    int idx = 1;
    bool found_left = false;
    bool found_right = false;

    while(!found_right)
    {
        struct ListNode *next = current_node->next;

        if(idx == right)
        {
            found_right = true;
            after_right = next;
        }

        if(idx == left)
        {
            before_left = last_node;
            original_left = current_node;
            found_left = true;
        }

        else if(idx > left)
        {
            current_node->next = last_node;
        }

        last_node = current_node;
        current_node = next;
        idx++;
    }

    before_left->next = last_node;
    original_left->next = after_right;

    return dummy_node.next;
    
}