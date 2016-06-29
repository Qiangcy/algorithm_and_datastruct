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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(-INT_MAX);
        ListNode* res_head = res;
        while(head) {
            if(res->val != head->val) {
                res->next = new ListNode(head->val);
                res = res->next;
            }
            head = head->next;
        }
        return res_head->next;
    }
};
