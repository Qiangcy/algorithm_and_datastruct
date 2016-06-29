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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(-INT_MAX);
        dummy_head->next = head;
        ListNode* reserve_head = dummy_head;
        while(dummy_head != nullptr && dummy_head->next != nullptr) {
            if(dummy_head->next->val == val) {
                ListNode* tmp = dummy_head->next;
                dummy_head->next = dummy_head->next->next;
                delete tmp;
            } else {
                dummy_head = dummy_head->next;
            }
        }
        return reserve_head->next;
    }
};


public ListNode removeElements(ListNode head, int val) {
        if (head == null) return null;
        head.next = removeElements(head.next, val);
        return head.val == val ? head.next : head;
}
