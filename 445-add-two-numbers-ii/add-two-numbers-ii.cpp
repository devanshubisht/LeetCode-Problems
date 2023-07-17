// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* Helper(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;

        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr;
        int carry = 0;

        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int digit1 = !stack1.empty() ? stack1.top() : 0;
            int digit2 = !stack2.empty() ? stack2.top() : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;

            if (!stack1.empty())
                stack1.pop();
            if (!stack2.empty())
                stack2.pop();
        }

        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = Helper(l1, l2);
        return ans;
    }
};
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* curr = l1;
//         ListNode* temp = nullptr;
//         ListNode* next = l1;
//         while (curr) {
//             next = curr->next;
//             curr->next = temp;
//             temp = curr;
//             curr = next;
//         }

//         ListNode* curr2 = l2;
//         ListNode* temp2 = nullptr;
//         ListNode* next2 = l2;
//         while (curr2) {
//             next2 = curr2->next;
//             curr2->next = temp2;
//             temp2 = curr2;
//             curr2 = next2;
//         }

//         curr = temp;
//         curr2 = temp2;

//         ListNode* result = Helper(curr, curr2);

//         // ListNode* result = new ListNode();
//         // ListNode* curr3 = result;
//         // int digit = 0;
//         // while (curr && curr2) {
//         //     curr3->val = ((curr2->val + curr->val) + digit)%10;
//         //     digit = ((curr2->val + curr->val) + digit)/10;
//         //     curr = curr->next;
//         //     curr2= curr2->next;
//         //     if (curr || curr2) {
//         //         curr3->next = new ListNode();
//         //         curr3 = curr3->next;
//         //     } 
//         // }

//         // while (curr2) {
//         //     curr3->val = (curr2->val + digit)%10;
//         //     digit = (curr2->val + digit)/10;
//         //     curr2 = curr2->next;
//         // }

//         // while (curr) {
//         //     curr3->val = (curr->val + digit)%10;
//         //     digit = (curr->val + digit)/10;
//         //     curr = curr->next;
//         // }

//         // while (digit) {
//         //     curr3->next = new ListNode(digit % 10);
//         //     digit /= 10;
//         //     curr3 = curr3->next;
//         // }

        
//         ListNode* currFinal = result;
//         ListNode* tempFinal = nullptr;
//         ListNode* nextFinal = result;
//         while (currFinal) {
//             nextFinal = currFinal->next;
//             currFinal->next = tempFinal;
//             tempFinal = currFinal;
//             currFinal = nextFinal;

//         }
//         return tempFinal;
        
//     }
//     ListNode* Helper(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* tail = dummyHead;
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int digit1 = (l1 != nullptr) ? l1->val : 0;
//             int digit2 = (l2 != nullptr) ? l2->val : 0;

//             int sum = digit1 + digit2 + carry;
//             int digit = sum % 10;
//             carry = sum / 10;

//             ListNode* newNode = new ListNode(digit);
//             tail->next = newNode;
//             tail = tail->next;

//             l1 = (l1 != nullptr) ? l1->next : nullptr;
//             l2 = (l2 != nullptr) ? l2->next : nullptr;
//         }

//         ListNode* result = dummyHead->next;
//         delete dummyHead;
//         return result;
//     }

// };



/// i could reverse it and then do it 
/// 

