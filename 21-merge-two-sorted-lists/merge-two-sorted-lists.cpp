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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        ListNode* head = newList;
        ListNode* prev = newList;
        while (list1 && list2) {
            ListNode* newNode = new ListNode();
            if (list1->val <= list2->val) {
                newNode->val = list1->val;
                list1 = list1->next;
            } else {
                newNode->val = list2->val;
                list2 = list2->next;
            }
            prev->next = newNode;
            prev = prev->next;
        }
        if (list1) {
            prev->next = list1;
        }
        if (list2) {
            prev->next = list2;
        }
        return head->next;
    }
};