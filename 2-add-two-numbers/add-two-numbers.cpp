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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* newVal = new ListNode();
        ListNode* start = newVal;
        int q = 0;
        int r = 0;
        while (l1 && l2) {
            r = (l1->val + l2->val + q) % 10;
            q = (l1->val + l2->val + q) / 10;

            newVal->next = new ListNode(r);
            newVal = newVal->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            r = (l1->val + q) % 10;
            q = (l1->val + q) / 10;

            newVal->next = new ListNode(r);
            newVal = newVal->next;

            l1 = l1->next;
        }
        while(l2) {
            r = (l2->val + q) % 10;
            q = (l2->val + q) / 10;

            newVal->next = new ListNode(r);
            newVal = newVal->next;


            l2 = l2->next;
        }
        if (q) {
            newVal->next = new ListNode(q);

        }

        return start->next;

    }

    ListNode* reverseNodes(ListNode* l1) {
        ListNode* prev = nullptr;
        while(l1) {
            ListNode* temp = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = temp;
        }
        return prev;
    }
};


// 1 2 3 
// 9 9 9 

// 3+9 

// remainder = num % 10
// quotinet = num / 10

// bring quotient to next one