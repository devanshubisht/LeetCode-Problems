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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        ListNode* head = dummy;
        int counter = 0;
        while(counter < a) {
            head = head->next;
            counter++;
        }
        ListNode* insertAt = head;
        while(counter < b + 1) {
            head = head->next;
            counter++;
        }
        ListNode* curr = list2;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head->next;

        insertAt->next = list2;
        return dummy->next;
    }
};