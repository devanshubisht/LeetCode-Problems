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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> hm;
        ListNode* curr = dummy;
        int prefix = 0;
        while (curr) {
            prefix += curr->val;
            if (prefix == 0) {
                head = curr->next;
            }
            if (hm.find(prefix) != hm.end()) {
                ListNode* oldHead = hm[prefix];
                ListNode* newHead = hm[prefix];
                newHead = newHead->next;
                int oldPrefix = prefix;
                while (newHead != curr) {
                    oldPrefix += newHead->val;
                    hm.erase(oldPrefix);
                    newHead = newHead->next;
                }
                oldHead->next = curr->next;
                curr = curr->next;
                continue;
            }
            hm[prefix] = curr;
            curr = curr->next;

        }
        return dummy->next;
    }
};