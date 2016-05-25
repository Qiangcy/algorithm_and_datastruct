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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesser_ListNode = new ListNode(-1);
        ListNode* lesser_ListNode_head = lesser_ListNode;
        ListNode* greater_ListNode = new ListNode(-1);
        ListNode* greater_ListNode_head = greater_ListNode;

        while(head) {
            if(head->val < x) {
                lesser_ListNode->next = new ListNode(head->val);
                lesser_ListNode = lesser_ListNode->next;
            }else {
                greater_ListNode->next = new ListNode(head->val);
                greater_ListNode = greater_ListNode->next;
            }
            head = head->next;
        }
        lesser_ListNode->next = greater_ListNode_head->next;
        return lesser_ListNode_head->next;
    }
};
