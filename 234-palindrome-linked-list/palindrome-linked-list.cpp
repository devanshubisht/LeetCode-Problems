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
    bool isPalindrome(ListNode* head) {
        ListNode* start = head;
        ListNode* prev = nullptr;
        while (head){
            ListNode* copy = new ListNode(head->val);
            copy->next = prev;
            head = head->next;
            prev = copy; 
        }

        while (prev && start) {
            if (prev->val != start->val) {
                return false;
            }
            prev = prev->next;
            start = start->next;
        }
        return true;

    }
};