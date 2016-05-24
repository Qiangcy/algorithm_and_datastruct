/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* res_head = res;
        int val , carry=0;
        for(;;) {
            if(l1 && l2) {
                val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1) {
                val = l1->val + carry;
                l1 = l1->next;
            }else if(l2) {
                val = l2->val + carry;
                l2 = l2->next;
            }

            if(val > 9) {
                val %= 10;
                carry = 1;
            }else {
                carry = 0;
            }

            res->val = val;
            if(l1==nullptr && l2==nullptr) {
                if(carry)
                    res->next = new ListNode(carry);
                else
                    res->next = nullptr;
                break;
            }else {
                res->next = new ListNode(0);
                res = res->next;
            }
        }
        return res_head;
    }
};
