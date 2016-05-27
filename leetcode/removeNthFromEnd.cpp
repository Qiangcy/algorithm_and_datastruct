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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* res_head = new ListNode(-INT_MAX);
            ListNode* res = res_head;
            res_head->next = head;
            ListNode* second = head;
            while(n--)
                second = second->next;

            while(second) {
                second = second->next;
                res = res->next;
            }
            ListNode* tmp = res->next;
            res->next = res->next->next;
            delete tmp;
            return res_head->next;
        }
};
