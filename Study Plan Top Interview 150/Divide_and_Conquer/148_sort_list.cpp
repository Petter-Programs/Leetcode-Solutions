/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* find_middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow->next && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    ListNode* merge_sorted(ListNode *first, ListNode *second)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while(first || second)
        {
            int first_val = first ? first->val : INT_MAX;
            int second_val = second ? second->val : INT_MAX;

            if(first_val < second_val)
            {
                curr->next = first;
                curr = first;
                first = first->next;
            }
            else
            {
                curr->next = second;
                curr = second;
                second = second->next;
            }
        }

        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;

        ListNode *left_start = head;
        ListNode *right_start = find_middle(head);
        
        // From our initial check and how the middle function works, we can assume this will exist
        ListNode *tmp = right_start->next;

        right_start->next = nullptr;
        right_start = tmp;
        
        // Assign these because the starting point may have changed
        left_start = sortList(left_start);
        right_start = sortList(right_start);

        ListNode *sorted = merge_sorted(left_start, right_start);

        return sorted;
        
    }
};