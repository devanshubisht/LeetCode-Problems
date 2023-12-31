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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode* before_curr = &before;
        ListNode* after_curr = &after;
        
        while(head) {
            if(head->val < x) {
                before_curr->next = head;
                before_curr = head;
            } else {
                after_curr->next = head;
                after_curr = head;
            }
            head = head->next;
        }
        
        after_curr->next = nullptr;
        before_curr->next = after.next; // for listnode object need to use . instead of ->
        
        return before.next;

    }
};

// partion is bring to the first indez, l
// while low is smaller than pivot. then while high is larger than pviot. find the one and then swap.make sure is while left smaller than high
//