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
    ListNode* merge_lists(ListNode* a, ListNode *b)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while(a || b)
        {
            int a_val = a ? a->val : INT_MAX;
            int b_val = b ? b->val : INT_MAX; 

            if(a_val < b_val)
            {
                curr->next = a;
                curr = a;
                a = a->next;
            }
            else
            {
                curr->next = b;
                curr = b;
                b = b->next;
            }
        }

        curr = dummy->next;
        delete dummy;
        return curr;
    }

    ListNode* div_and_conq(vector<ListNode*>& lists, int start_idx, int end_idx)
    {
        if(end_idx-start_idx <= 1)
        {
            if(end_idx-start_idx != 1)
            {
                std::cout << "divided and conquered a bit too much" << std::endl;
                return nullptr;
            }

            return lists[start_idx];
        }

        else if(end_idx-start_idx > 2)
        {
            ListNode *list_one = div_and_conq(lists, start_idx, (start_idx+end_idx)/2);
            ListNode *list_two = div_and_conq(lists, (start_idx+end_idx)/2, end_idx);

            return merge_lists(list_one, list_two);
        }

        else
        {
            return merge_lists(lists[start_idx], lists[start_idx+1]);
        }

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

        if(lists.size() == 0)
            return nullptr;

        // naive solution: 
        // loop through each of the linked lists, grap the lowest value start,
        // continue until no more to grab
        // for each value inserting, need to go through all the remaining values
        // so O(N**2)

        // better:
        // merge two at a time, halving the problem size at each step
        // need logn halves, at each step O(N) 
        // so O(NlogN)

      return div_and_conq(lists, 0, lists.size());
        
    }
};