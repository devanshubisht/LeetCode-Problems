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
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        ListNode* copy = head;
        while(copy) {
            copy = copy->next;
            num++;
        }
        int mid = num / 2;
        int start = 0;
        while(start < mid) {
            head = head->next;
            start++;
        }
        return head;
    }
};